package sample;

import java.net.*;
import java.io.*;
import java.net.URL;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

import javax.swing.*;

public class Controller extends Thread {

    @FXML
    ResourceBundle resources;

    @FXML
    URL location;

    @FXML
    Button gui_button_connect;

    @FXML
    TextField gui_input_ip;

    @FXML
    TextField gui_input_port;

    @FXML
    TextArea gui_field_log;

    @FXML
    TextArea gui_field_status;

    boolean flag_connect = false;
    @FXML
    void initialize() {
        Platform.runLater(() -> gui_field_status.setText("-> Status: Offline\n"));
        gui_button_connect.setOnAction(event -> {
            if (flag_connect == false) {
                Connect connect = new Connect();
                try (DataInputStream read = connect.read;
                     DataOutputStream write = connect.write;) {
                    connect.start();
                    flag_connect = true;
                } catch (IOException e) {
                    e.printStackTrace();
                    flag_connect = false;
                    try {
                        connect.socket.close();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            }
        });
    }

    public class Connect extends Thread  {
        Socket socket;
        DataInputStream read;
        DataOutputStream write;
        String ip;
        int port;

        public void run() {
            try {
                ip = gui_input_ip.getText();
                port = Integer.parseInt(gui_input_port.getText());
                socket = new Socket(ip, port);
                read = new DataInputStream(socket.getInputStream());
                write = new DataOutputStream(socket.getOutputStream());
                Platform.runLater(() -> gui_field_status.setText("-> Status: Online\n"));
                Platform.runLater(() -> gui_field_log.appendText("Waiting task...\n"));
            } catch (IOException e) {
                e.printStackTrace();
                Platform.runLater(() -> gui_field_status.setText("-> Failed connection\n"));
                Platform.runLater(() -> gui_field_status.appendText("-> Status: Offline\n"));
            }

            try {
                while (true) {

                    write.writeUTF("get_data");
                    int left = read.readInt();
                    int right = read.readInt();
                    int found_num = 0;
                    for (int i = left; i < right; i++) {
                        if (i % 11 == 0 && i % 13 == 0 && i % 17 == 0) {
                            int finalI = i;
                            Platform.runLater(() -> gui_field_log.appendText(finalI + "\n"));
                            found_num++;
                        }
                    }
                    int finalFound_num = found_num;
                    write.writeUTF("in_data");
                    write.writeInt(found_num);
                }
            } catch (IOException e) {
                try {
                    read.close();
                    write.close();
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
                e.printStackTrace();
            }
        }
    }
}
