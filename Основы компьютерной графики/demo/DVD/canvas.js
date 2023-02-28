var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d");
canvas.width = document.body.clientWidth; // Получаем ширину страницы браузера
canvas.height = document.body.clientHeight; // Получаем высоту страницы браузера
var DVDWIDTH = 418; // Ширина надписи DVD
var DVDHEIGHT = 138; // Высота надписи DVD
var x = canvas.width / 2 - DVDWIDTH / 2; // Начальное смещение по оси X
var y = canvas.height / 2 - DVDHEIGHT / 2 - 85; // Начальное смещение по оси Y
var dx = 2; // Угол отражения X
var dy = -2; // Угол отражения Y
var color = 'BLUE'; // Цвет для заливки

// Функция возвращает случайный цвет
function getRandomColor() {
    var letters = '0123456789ABCDEF';
    var color = '#';
    for (var i = 0; i < 6; i++) color += letters[Math.floor(Math.random() * 16)];
    return color;
}

// Функция рисует эллипс с помощью кривых Безье
function drawEllipse(centerX, centerY, width, height) {
    ctx.beginPath();
    ctx.moveTo(centerX, centerY - height / 2);
    ctx.bezierCurveTo(centerX + width / 2, centerY - height / 2,centerX + width / 2, centerY + height / 2,centerX, centerY + height / 2);
    ctx.bezierCurveTo(centerX - width / 2, centerY + height / 2,centerX - width / 2, centerY - height / 2,centerX, centerY - height / 2);
    ctx.fillStyle = color;
    ctx.fill();
    ctx.closePath();
}

// Основная функция. Отрисовка. Логика. Анимация.
function animation() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    // Рисуем надпись DVD по координатам которые находятся в файле a_coordinates.js
    ctx.beginPath();
    ctx.moveTo(x + DVD[0], y + DVD[0]);
    for (i = 0; i < DVD.length; i += 2)
        ctx.lineTo(x + DVD[i], y + DVD[i + 1]);
    ctx.fillStyle = color;
    ctx.fill();

    // Рисуем эллипс
    drawEllipse(x + DVDWIDTH / 2 - 20, 100 + y + DVDHEIGHT - 75, 540, 50);

    // Рисуем надпись "VIDEO"
    ctx.fillStyle = "BLACK";
    ctx.font = 'bold 40px sans-serif'
    ctx.fillText("V I D E O", x + 100, y + DVDHEIGHT + 40);

    // Логика анимации. "Угол падения равен углу отражения."
    if (x + dx > canvas.width - DVDWIDTH || x + dx < 0) {
        dx = -dx;
        color = getRandomColor();
    }
    if (y + dy > canvas.height - DVDHEIGHT - 50 || y + dy < 0) {
        dy = -dy;
        color = getRandomColor();
    }

    x += dx;
    y += dy;
}

// setInterval выполняет код много раз, через равные промежутки времени (АНИМАЦИЯ)
setInterval(animation, 10);