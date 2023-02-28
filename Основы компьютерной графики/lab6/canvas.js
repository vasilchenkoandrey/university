canvas = document.getElementById("canvas");
ctx = canvas.getContext('2d');
var arrL = [],
    cData = [],
    data = [],
    mx, ym, speed = 0.0001;

function plot() {
    for (var x = -5; x <= 5; x += 0.1)
        for (var y = -5; y <= 5; y += 0.5) {
            z = Math.sin(x) * Math.cos(y) * Math.cos(y);
            data.push(new data3D(x, y, z));
        }
}
const data2D = function(x, y) {
    this.x = x;
    this.y = y;
};
const data3D = function(x, y, z) {
    this.x = x;
    this.y = y;
    this.z = z;
};
function cos(x) {return Math.cos(x*speed)}
function sin(x) {return Math.sin(x*speed)}
function rotation(x, y) {
    for (var i = 0; i < data.length; i++) {
        data[i].x = data[i].x;
        data[i].y = data[i].y * cos(y) + data[i].z * sin(y);
        data[i].z = data[i].z * cos(y) - data[i].y * sin(y);

        data[i].x = data[i].z * sin(x) + data[i].x * cos(x);
        data[i].y = data[i].y;
        data[i].z = data[i].z * cos(x) - data[i].x * sin(x);
    }
}

function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    canvas.onmousemove = function(event) {mx = event.offsetX - canvas.width / 2; ym = event.offsetY - canvas.height / 2;}
    if (mx) rotation(mx, ym)
    cData = calculate(data);
    ctx.strokeStyle = 'green';
    for (var i = 0; i < arrL.length; i += 21) {
        ctx.beginPath();
        ctx.moveTo(cData[i].x, cData[i].y);
        for (j = i + 1; j < i + 20; j++)
            ctx.lineTo(cData[j].x, cData[j].y);
        ctx.stroke();
        ctx.closePath();
    }
    requestAnimationFrame(draw);
}

function calculate(arr) {
    arrL = new Array(arr.length);
    var f = 100;
    for (var i = 0; i < arr.length; i++) {
        let p = arr[i];
        let x = 50 * f * p.x / (p.z + f) + 400;
        let y = 50 * f * p.y / (p.z + f) + 400;
        arrL[i] = new data2D(x, y);
    }
    return arrL;
}

plot();
draw();