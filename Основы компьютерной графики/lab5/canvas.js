var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');

var oxy = canvas.width / 2; // Центр канвы
var x = 1000; // Начальная координата мыши по оси X
var y = 1000; // Начальная координата мыши по оси Y
var moveX = 0; // Начальное смещение по оси X для движения объектов
var moveY = 0; // Начальное смещение по оси Y для движения объектов
var moveLimitX = 350; // Предел движения "корабля" по оси X. (Чем больше, тем меньше область движения для "корабля")
var moveLimitY = 350; // Предел движения "корабля" по оси Y. (Чем больше, тем меньше область движения для "корабля")

var particles = []; // Переменная для хранения "звезд на заднем плане"
var particlesColor = ["#ffffff", "#9ceefa", ]; // Цвет звезд
var colorHEX = 0; // Счетчик для перебора цветов звезд. Т.е. начинаем с particlesColor[0]
var requestAnimation; // Переменная для вызова функции requestAnimationFrame(); (для анимации)

var moveFireX = 5 + Math.random() * 5; // Анимация огня (рандомное смещение контуров огня по оси X)
var moveFireY = 10 + Math.random() * 100; // Анимация огня (рандомное смещение контуров огня по оси Y)
var speedSpaceshipX = Math.random() * (2 - (-2)) - 2; // Задаем рандомную скорость "корабля" по оси X
var speedSpaceshipY = Math.random() * (2 - (-2)) - 2; // Задаем рандомную скорость "корабля" по оси Y

// Булевые переменные назначение которых будет ясно ниже
var bool = false;
var isPaused = false;
var aimX;
var aimY;
////////////////////////////////////////////////////////

// Массивы с координатами отдельных частей "корабля"
var bodyX = [5, 24, 36, 39, 34, 30, -30, -34, -39, -36, -24, -5, 5]; // Основная часть "корабля" по X
var bodyY = [-85, -63, -25, 16, 76, 97, 97, 76, 16, -25, -63, -85, -85]; // Основная часть "корабля" по Y

var lWingX = [-41, -36, -89, -98, -93, -85, -41]; // Левое крыло "корабля" по X
var lWingY = [16, 76, 100, 100, 18, 65, 16]; // Левое крыло "корабля" по Y

var rWingX = [41, 36, 89, 98, 93, 85, 41]; // Правое крыло "корабля" по X
var rWingY = [16, 76, 100, 100, 18, 65, 16]; // Правое крыло "корабля" по Y

var noseX = [-5, 0, 5, -5, ]; // Носовая часть "корабля" по X
var noseY = [-87, -109, -87, -87]; // Носовая часть "корабля" по Y

var turbineX = [31, 36, -36, -31, 31]; // Турбина "корабля" по X
var turbineY = [99, 111, 111, 99, 99]; // Турбина "корабля" по Y

var fireX = [22, 22 + moveFireX, 0, -22 - moveFireX, -22, 22]; // Внешний огонь из турбины "корабля" по X
var fireY = [113, 144 + moveFireY, 201, 144 + moveFireY, 113, 113]; // Внешний огонь из турбины "корабля" по Y

var fireSmallX = [12, 12 + moveFireX, 0, -12 - moveFireX, -12, 12]; // Внутренний огонь из турбины "корабля" по X
var fireSmallY = [113, 135 + moveFireY, 165 + moveFireY, 135 + moveFireY, 113, 113]; // Внутренний огонь из турбины "корабля" по Y
///////////////////////////////////////////////////

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
            drawStroke(xp, yp); // ... отрисовуем контур многоугольника в который точка входит,
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

// Функция для отрисовки контура многоугольника
function drawStroke(xp, yp) { // Параметры (xp - вершина многоугольника по оси X, yp - вершина многоугольника по оси Y)
    ctx.beginPath();
    ctx.moveTo(moveX + oxy + xp[0], moveY + oxy + yp[0]);
    for (i = 0; i < xp.length; i++) {
        ctx.lineTo(moveX + oxy + xp[i], moveY + oxy + yp[i]);
    }
    ctx.lineWidth = 2;
    ctx.strokeStyle = "red";
    ctx.stroke();
    ctx.closePath();

}
//////////////////////////////////////////////

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

// Функция для создания обектов (звезд)
function createParticles() {
    colorHEX++; // Инкрементирование счетчика для постоянной смены цветов "звезд"
    if (colorHEX > particlesColor.length) colorHEX = 0; // Чтобы счетчик не вылез за пределы количества цветов 
    if (particles.length < 100) { // Максимальное количество звезд на экране (в канве)
        particles.push({ // Добавляем в массив particles объекты (звезды) со следующими характеристиками:
            x: Math.random() * canvas.width, // начальное расположение по оси X задаем рандомом,
            y: 0, // начальное расположение по оси Y,
            speed: 2 + Math.random() * 25, // скорость объектов (звезд), задаем рандомно,
            radius: Math.random() * 1.5, // размер объектов (радиус звезд), задаем рандомно
            color: particlesColor[colorHEX], // цвет объектов (звезд), берез значение из массива particlesColor()
        });
    }
}
/////////////////////////////////////////////

// Функция для вызова "звезд"
function updateParticles() {
    for (var i in particles) {
        var part = particles[i];
        part.y += part.speed;
    }
}
/////////////////////////////

// Функция для уничтожения объектов (звезд) за пределами экрана (канвы)
function killParticles() {
    for (var i in particles) {
        var part = particles[i];
        if (part.y > canvas.height) {
            part.y = 0;
        }
    }
}
//////////////////////////////////////////////////////////////

// Функция отрисовывает наши объекты (звезды)  
function drawParticles() {
    ctx.fillStyle = "black";
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    for (var i in particles) {
        var part = particles[i];
        ctx.beginPath();
        ctx.arc(part.x, part.y, part.radius, 0, Math.PI * 2);
        ctx.closePath();
        ctx.fillStyle = part.color;
        ctx.fill();
    }
}
/////////////////////////////////////////////

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
        createParticles();
        updateParticles();
        killParticles();
        drawParticles();
		
		// Логика движения "корабля"
        if ((moveX + oxy + moveLimitX < canvas.width || moveY + oxy + moveLimitY < canvas.height) && bool == false) {
            moveX += 3;
            moveY += speedSpaceshipY;
            if (moveX + oxy + moveLimitX >= canvas.width || moveY + oxy + moveLimitY >= canvas.height) {
                bool = true;
                speedSpaceshipY = Math.random() * (1 - (-1)) - 1;
            }
        } else {
            moveX -= 3;
            moveY -= speedSpaceshipY;
            if (moveX + oxy - moveLimitX <= 0 || moveY + oxy - moveLimitY <= 0) bool = false;
		}
		//////////////////////////////

        // Цвет для основной части корабля, задаем линейным градиентом
        var grad = ctx.createLinearGradient(0, moveX + oxy, (moveX + oxy) * 2, moveX + oxy);
        grad.addColorStop(0, 'rgba(70,102,89,1)');
        grad.addColorStop(0.50, 'rgba(70,102,89,1)');
        grad.addColorStop(0.50, 'rgba(90,134,121,1)');
        grad.addColorStop(1, 'rgba(90,134,121,1)');
        ///////////////////////////////////////////////////////////////

        
        moveFireX = 5 + Math.random() * 5;
		moveFireY = 10 + Math.random() * 100;
		
		// Отрисовываем внешний огонь
        ctx.beginPath();
        ctx.moveTo(moveX + oxy + 22, moveY + oxy + 113);
        ctx.lineTo(moveX + oxy + 22 + moveFireX, moveY + oxy + 144 + moveFireY);
        ctx.lineTo(moveX + oxy, moveY + oxy + 201);
        ctx.lineTo(moveX + oxy - 22 - moveFireX, moveY + oxy + 144 + moveFireY);
        ctx.lineTo(moveX + oxy - 22, moveY + oxy + 113);
        ctx.lineTo(moveX + oxy + 22, moveY + oxy + 113);
        ctx.closePath();
        ctx.fillStyle = "#f95120";
        ctx.fill();
		//////////////////////////////

        // Отрисовываем внутренний огонь
        ctx.beginPath();
        ctx.moveTo(moveX + oxy + 12, moveY + oxy + 113);
        ctx.lineTo(moveX + oxy + 12 + moveFireX, moveY + oxy + 135 + moveFireY);
        ctx.lineTo(moveX + oxy, moveY + oxy + 165 + moveFireY);
        ctx.lineTo(moveX + oxy - 12 - moveFireX, moveY + oxy + 135 + moveFireY);
        ctx.lineTo(moveX + oxy - 12, moveY + oxy + 113);
        ctx.lineTo(moveX + oxy + 12, moveY + oxy + 113);
        ctx.closePath();
        ctx.fillStyle = "#fba542";
        ctx.fill();
        ////////////////////////////////

		// Вызываем функцию отрисовки для каждого многоугольника (части корабля)
        draw(bodyX, bodyY, grad);
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
            check(fireX, fireY, x, y);
            check(fireSmallX, fireSmallY, x, y);
		};
		//////////////////////////////////////////////////////

        // Отрисовываем иллюминатор
        ctx.beginPath();
        ctx.arc(moveX + oxy, moveY + oxy + -20, 15, 0, 2 * Math.PI);
        ctx.lineWidth = 6;
        ctx.strokeStyle = "#e6f1ed";
        ctx.stroke();
        ctx.fillStyle = "#2f4d4f";
        ctx.fill();
		/////////////////////////////

        // Отрисовываем блики на стекле иллюминатора
        ctx.beginPath();
        ctx.arc(moveX + oxy + 6, moveY + oxy + -27, 2, 0, 2 * Math.PI);
        ctx.fillStyle = "#bdc4ca";
        ctx.fill();
        /////////////////////////////////////////////
    }

    requestAnimation = requestAnimationFrame(pictures); // Обновляем кадры экрана (канвы) с помощью функции requestAnimationFrame()
}

requestAnimationFrame(pictures);