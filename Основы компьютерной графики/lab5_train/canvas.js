var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');

var oxy = canvas.width / 2; // Центр канвы
var x = -1000; // Начальная координата мыши по оси X
var y = -1000; // Начальная координата мыши по оси Y
var moveX = -600; // Начальное смещение по оси X для движения объектов
var moveY = 0; // Начальное смещение по оси Y для движения объектов
var requestAnimation; // Переменная для вызова функции requestAnimationFrame(); (для анимации)

// Булевые переменные назначение которых будет ясно ниже
var bool = false;
var isPaused = false;
var aimX;
var aimY;
////////////////////////////////////////////////////////

var bodyX = [32, 103, 103, 32]; 
var bodyY = [49,49, 159, 159]; 

var lWingX = [18, 116, 116, 18]; 
var lWingY = [33, 33, 47, 47]; 

var rWingX = [103, 192, 192, 103]; 
var rWingY = [94, 94, 159, 159]; 

var noseX = [51, 83, 83, 51]; 
var noseY = [55, 55, 95, 95]; 

var turbineX = [161, 192, 192, 161]; 
var turbineY = [66, 66, 93, 93];

// Функция возвращает координаты мыши
canvas.onmousemove = function(event) {
    mouseX = event.offsetX - oxy;
    mouseY = event.offsetY - oxy;
    x = mouseX;
    y = mouseY;
}
//////////////////////////////

// Функция для проверки принадлежит ли точка многоугольнику 
function inPoly(xp, yp, x, y) { // Параметры (xp - вершина многоугольника по оси X, yp - вершина многоугольника по оси Y, x - координата точки (мыши) по оси X, y - координата точки (мыши) по оси Y)
    npol = xp.length;
    j = npol - 1;
    var c = 0;
    for (i = 0; i < npol; i++) {
        if ((((moveY + yp[i] <= y) && (y < moveY + yp[j])) || ((moveY + yp[j] <= y) && (y < moveY + yp[i]))) &&
            (x > (moveX + xp[j] - moveX - xp[i]) * (y - moveY - yp[i]) / (moveY + yp[j] - moveY - yp[i]) + moveX + xp[i])) {
            c = !c
        }
        j = i;
    }
    return c;
}
/////////////////////////////////////////////////////////

// Функция для проверки вхождения точки в многоугольник, отрисовки контура многоугольника в который входит точка и паузы анимации
function check(xp, yp, x, y) { // Параметры (xp - вершина многоугольника по оси X, yp - вершина многоугольника по оси Y, x - координата точки (мыши) по оси X, y - координата точки (мыши) по оси Y)
    if (inPoly(xp, yp, x, y) != 0) // Если точка принадлежност многоугольнику, то...
        if (xp != 0 && yp != 0) { // ... если координаты многоугольника не пусты, то...
            drawStroke(xp, yp) // ... отрисовуем контур многоугольника в который точка входит,
            isPaused = true; // и ставим анимацию на паузу.
            canvas.onmousedown = function(event) { // Отслеживаем нажатие левой кнопки мыши.
                if (isPaused == true) { // Если пауза уже стоит, то...
                    {
                        xp = 0; // ... освобождаем переменную с координатами контура выбранного многоугольника по оси X
                        yp = 0; // и по оси Y, для дальнейших проверок других многоугольников. 
                        isPaused = false; // и убираем паузу анимации.
                    }
                }

            };
        }
}
//////////////////////////////////////////////////////

// Функция для рисования многоугольников по координатам
function draw(xp, yp, color) { // Параметры (xp - вершина многоугольника по оси X, yp - вершина многоугольника по оси Y, color - цвет заливки многоугольника в HEX)
    ctx.beginPath();
    ctx.moveTo(moveX + oxy + xp[0], moveY + oxy + yp[0]);
    for (i = 0; i < xp.length; i++) {
        ctx.lineTo(moveX + oxy + xp[i], moveY + oxy + yp[i]);
    }
    ctx.fillStyle = color;
    ctx.fill();
    ctx.closePath();
}
//////////////////////////////////////////////////////////

function drawStroke(xp, yp) { // Параметры (xp - вершина многоугольника по оси X, yp - вершина многоугольника по оси Y)
    ctx.beginPath();
    ctx.moveTo(moveX + oxy + xp[0], moveY + oxy + yp[0]);
    for (i = 0; i < xp.length; i++) {
        ctx.lineTo(moveX + oxy + xp[i], moveY + oxy + yp[i]);
    }
    ctx.fillStyle = "red";
    ctx.fill();
    ctx.closePath();

}

// Пауза анимации
window.requestAnimFrame = (function() {
    return window.requestAnimationFrame ||
        window.webkitRequestAnimationFrame ||
        window.mozRequestAnimationFrame ||
        function(callback) {
            window.setTimeout(callback, 1000 / 60);
        };
})();
///////////////////

// Функция для обновления кадров экрана (канвы) (АНИМАЦИЯ!) Сюда помещаем функции которые необходимо вызывать при каждом обновлении кадра.
function pictures() {
    if (!isPaused) {
        ctx.clearRect(0, 0, canvas.width, canvas.height); // Обязательно сначала стираем все с экрана (канвы), потом "рисуем" !
		
		// Логика движения "корабля"
        if ((moveX + oxy < canvas.width) && bool == false) {
            moveX ++;
            if (moveX + oxy >= canvas.width) {
                bool = true;
            }
        } else {
            moveX = -600;
            if (moveX <= 0) bool = false;
		}
		

		// Вызываем функцию отрисовки для каждого многоугольника (части корабля)
        draw(bodyX, bodyY, "#314f51");
        draw(lWingX, lWingY, '#314f51');
        draw(rWingX, rWingY, '#314f51');
        draw(noseX, noseY, '#243738');
		draw(turbineX, turbineY, '#2f4d4f');
		///////////////////////////////////////
		
		// При нажатии на левую кнопку мышки вызываем функцию для проверки принадлежности точки многоугольнику, отрисовки контура данного многоугольника и пазы анимации.
        canvas.onmousedown = function(event) {
            check(bodyX, bodyY, x, y);
            check(lWingX, lWingY, x, y);
            check(rWingX, rWingY, x, y);
            check(noseX, noseY, x, y);
            check(turbineX, turbineY, x, y);
		};
        //////////////////////////////////////////////////////

        ctx.beginPath();
        ctx.arc(55 + moveX + oxy,159 + moveY + oxy + -20, 30, 0, 2 * Math.PI);
        ctx.lineWidth = 6;
        ctx.strokeStyle = "#e6f1ed";
        ctx.stroke();
        ctx.fillStyle = "#2f4d4f";
        ctx.fill();

        ctx.beginPath();
        ctx.arc(150 + moveX + oxy,164 + moveY + oxy + -20, 25, 0, 2 * Math.PI);
        ctx.lineWidth = 6;
        ctx.strokeStyle = "#e6f1ed";
        ctx.stroke();
        ctx.fillStyle = "#2f4d4f";
        ctx.fill();
    }

    requestAnimation = requestAnimationFrame(pictures); // Обновляем кадры экрана (канвы) с помощью функции requestAnimationFrame()
}

requestAnimationFrame(pictures);