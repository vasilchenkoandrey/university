package sample;

import java.io.*;
import java.net.*;
import java.util.*;

public class Server {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int _port = 27015;
		Session session = new Session(_port);
		while (true) session.AddTask(in.nextInt() + " " + in.nextInt() + " " + in.nextInt() + " ");
	}
}

class Session extends Thread {

	ServerSocket server;
	Queue<String> queue_task = new LinkedList<String>();
	Queue<Integer> cuts = new LinkedList<Integer>();

	boolean finish = true;
	int 	LEFT = 0,
			RIGHT = 0,
			STEP = 0,
			NUM_CUTS = 0,
			sum_found_num = 0,
			parts = 0,
			id = 0;

	public Session(int port) {
		try {
			server = new ServerSocket(port);
			start();
			System.out.println("======================\n" +
							   "The server is running." +
							   "\n======================");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void run() {
		Socket socket = null;
		try {
			while (true) {
				socket = server.accept();
				new Communication(socket);
				id++;
				System.out.println(" -> Client#" + id + " connected!");
			}

		} catch (IOException e) {
			System.out.println("Connection Error: " + socket);
		}
	}

	public void AddTask(String input) {
		queue_task.add(input);
		System.out.println("\n\n\n============================\n" +
				"New task: " +  input +
				"\n============================");
		Awake();
	}

	synchronized public void SplitData() {
		String[] line = queue_task.peek().split(" ");
		queue_task.remove();
		LEFT = Integer.parseInt(line[0]);
		RIGHT = Integer.parseInt(line[1]);
		STEP = Integer.parseInt(line[2]);
		Cuts();
	}

	synchronized public void Cuts() {
		for (int i = LEFT; i < RIGHT; i += STEP) {
			if (i + STEP <= RIGHT) {
				cuts.add(i);
				cuts.add(i + STEP);
			}
		}
		NUM_CUTS = cuts.size() / 2;
	}

	synchronized public Integer[] CreateTask() {
		while (cuts.isEmpty()) {
			if (!queue_task.isEmpty()) {
				SplitData();
				break;
			}
			Sleep();
		}
		finish = true;
		Integer[] new_ab = new Integer[2];
		new_ab[0] = cuts.remove();
		new_ab[1] = cuts.remove();
		return new_ab;
	}

	synchronized public void InputResultat(int found_num) {
		if (finish) {
			sum_found_num += found_num;
			parts++;
			if (NUM_CUTS == parts) {
				finish = false;
				System.out.println("\n------------- Task completed -------------" +
								   "\nLeft Right Step: " + LEFT + " " + RIGHT + " " + STEP +
								   "\nNumber of partitions: " + parts +
								   "\nNumber of numbers found: " + sum_found_num +
								   "\n------------------------------------------\n\n\n\n\n\n");
				sum_found_num = 0;
				parts = 0;
				Awake();
			}
		}
	}

	synchronized public void Sleep() {
		try {
			wait();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	synchronized public void Awake() {
		this.notifyAll();
	}

	class Communication extends Thread {
		DataInputStream read;
		DataOutputStream write;

		public Communication(Socket socket) {
			try {
				read = new DataInputStream(socket.getInputStream());
				write = new DataOutputStream(socket.getOutputStream());
				start();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		public void run() {
			String request;

			while (true) {
				try {
					request = read.readUTF();
					if (request.equals("in_data")) InputResultat(read.readInt());
					if (request.equals("get_data")) Write(CreateTask());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}

		synchronized public void Write(Integer[] array) {
			try {
				List<Integer> data = new ArrayList<Integer>();
				data = Arrays.asList(array);
				for (int i: data) {
					write.writeInt(i);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}