var canvas = document.getElementById('canvas');
var context = canvas.getContext('2d');
var requestAnimation;
var coor = {x1:400,y1:250,r1:1,x2:400,y2:250,r2:270};

// Рисуем объекты по координатам которые находятся в файле a_coor.js
function draw(bitMap, color) {
    for (var i = 0; i < bitMap.length; i = i + 2)
        if (i == 0) context.beginPath();
        else context.lineTo(bitMap[i], bitMap[i + 1]);
    context.fillStyle = color;
    context.fill();
}

// Рисуем объекты с анимацией по координатам которые находятся в файле a_coor.js
function drawAnimation(bitMap) {
    context.beginPath();
    for (var i = 0; i < bitMap.length; i = i + 2) {
        context.clearRect(bitMap[i], bitMap[i + 1]--, 0, 0);
        context.lineTo(bitMap[i], bitMap[i + 1]--);
    }
    var grad = context.createRadialGradient(coor.x1,coor.y1,coor.r1,coor.x2,coor.y2,coor.r2);
    grad.addColorStop(0, 'rgba(64,64,64,1)');
    grad.addColorStop(1, 'rgba(10,10,10,0.99)');
    context.setTransform(1,0,0,1,0,0);
    context.fillStyle = grad;
    context.fill();
}

// Обновляем кадры при помощи requestAnimationFrame();
function animation() {

    context.fillStyle = "white";
    context.clearRect(0, 0, canvas.width, canvas.height);

    // Массив имен массивов с координатами которые находятся в файле a_coor.js
    ball = [airBall1, airBall2, airBall3, airBall4, airBall5, airBall6, airBall7, airBall8, airBall9, airBall10, airBall11, airBall12, airBall13, airBall14, airBall15, airBall16, airBall17, airBall18, airBall19, airBall20, airBall21, airBall22, airBall23];
    // Вызываем функцию рисования по координатам
    for (i = 0; i < ball.length; i++)
        drawAnimation(ball[i]);

    // Массив имен массивов с координатами которые находятся в файле a_coor.js
    object = [{'name': face, 'color': "#fefefe"}, {'name': heir, 'color': "#B22417"}, {'name': maskEyeLeft, 'color': "#8a241f"}, {'name': maskEyeRight, 'color': "#8a241f"}, {'name': mask, 'color': "#8a241f"}, {'name': maskNose, 'color': "#8a241f"}, {'name': conturFace, 'color': "#2b2a29"}, {'name': conturRightEye, 'color': "#2b2a29"}, {'name': conturLeftEye, 'color': "#2b2a29"}, {'name': conturNoseTop, 'color': "#2b2a29"}, {'name': conturNoseBottom, 'color': "#2b2a29"}, {'name': conturFall, 'color': "#fffff"}, {'name': conturHeirTop, 'color': "#8a241f"}, {'name': conturHeirBottom, 'color': "#8a241f"}, {'name': nose, 'color': "#bf2223"}, {'name': smile, 'color': "#bf2223"}, {'name': eyeWhiteLeft, 'color': "#fefefe"}, {'name': eyeWhiteRight, 'color': "#fefefe"}, {'name': blickEyeLeft, 'color': "#fefefe"}, {'name': blickEyeRight, 'color': "#fefefe"}, {'name': blickNose, 'color': "#fefefe"}, {'name': tooth, 'color': "#fefefe"}, {'name': blickSmileLeft, 'color': "#fefefe"}, {'name': blickSmileRight, 'color': "#fefefe"}, {'name': eyeballLeft, 'color': "#fecc00"}, {'name': eyeballRight, 'color': "#fecc00"}, {'name': conturEyeballLeft, 'color': "#d05d20"}, {'name': conturEyeballRight, 'color': "#d05d20"}, {'name': earLeft, 'color': "#fefefe"}, {'name': earRight, 'color': "#fefefe"}];
    // Вызываем функцию рисования по координатам
    for (i = 0; i < object.length; i++)
        draw(object[i].name, object[i].color);

    drawAnimation(airBallBig, "#000");

    requestAnimation = requestAnimationFrame(animation);
}
requestAnimationFrame(animation);
