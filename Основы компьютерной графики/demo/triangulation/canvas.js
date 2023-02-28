var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');

//Координаты многоугольника
var polygon = [290, 115, 333, 110, 381, 145, 390, 153, 355, 161, 390, 189, 354, 203, 380, 226, 377, 286, 429, 307, 416, 323, 475, 354, 550, 373, 626, 416, 654, 434, 684, 576, 680, 581, 621, 528, 611, 440, 592, 431, 591, 502, 582, 552, 608, 596, 598, 679, 576, 716, 544, 711, 582, 617, 579, 593, 530, 566, 527, 622, 475, 692, 455, 715, 429, 711, 474, 631, 495, 601, 453, 509, 448, 487, 352, 462, 285, 442, 253, 443, 207, 481, 227, 506, 245, 508, 258, 539, 213, 536, 140, 463, 164, 379, 215, 380, 207, 309, 223, 286, 229, 212, 178, 228, 142, 242, 117, 214, 199, 121, 202, 97, 235, 106, 282, 87, 286, 116];
//Создаем массив с индексами вершин треугольников с помощью функции earcut()
var node = earcut(polygon);
//Массив с координатами треугольников
var triangle = [];

//Заполняем массив с координатами треугольников путем объединения массива с индексами и массива координат многоугольника 
for (var i = 0; i < node.length; i++) {
    triangle.push(polygon[node[i] * 2]); triangle.push(polygon[node[i] * 2 + 1]);
}

//Функция возвращает случайный цвет
function getRandomColor() {
    var letters = '0123456789ABCDEF';
    var color = '#';
    for (var i = 0; i < 6; i++) {
        color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
}

//Функция отрисовки многоугольника по координатам
function drawPoligon(bitMap, color) {
    for (var i = 0; i < bitMap.length; i = i + 2)
        if (i == 0) ctx.moveTo(bitMap[i], bitMap[i + 1]);
        else ctx.lineTo(bitMap[i], bitMap[i + 1]);
    ctx.closePath();
    ctx.strokeStyle = color;
    ctx.stroke();
}

//Функция отрисовки треугольников с случайным цветом заливки
function drawTriangle(bitMap) {
    ctx.beginPath();
    ctx.moveTo(bitMap[0], bitMap[1]);
    ctx.lineTo(bitMap[2], bitMap[3]);
    ctx.lineTo(bitMap[4], bitMap[5]);
    ctx.closePath();
    ctx.fillStyle = getRandomColor();
    ctx.fill();

    for (var i = 6; i <= bitMap.length - 6; i += 6) {
        ctx.beginPath();
        ctx.lineTo(bitMap[i], bitMap[i + 1]);
        ctx.lineTo(bitMap[i + 2], bitMap[i + 3]);
        ctx.lineTo(bitMap[i + 4], bitMap[i + 5]);
        ctx.closePath();
        ctx.fillStyle = getRandomColor();
        ctx.fill();
    }
}

drawPoligon(polygon, 'black');
drawTriangle(triangle);