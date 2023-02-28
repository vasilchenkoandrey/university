var canvas = document.getElementById('canvas');
var context = canvas.getContext('2d');

// Размеры окна браузера
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

// Центр окна браузера
var oy = canvas.height / 2;
var ox = canvas.width / 2;

var particles = []; // Массив для частиц
var particlesCount = 121; // Количество частиц

// Свойства частиц
function newParticle(i) {
    particles[i] = this;
	this.i = i;
	this.velocity = 1;
	this.spaceRadius = 200; // Радиус отдаленности частиц
	this.radiusParticle = 2; // Размер частиц (радиус)
	this.moveLimit = 5; // Предел частиц
	this.holeRadius = 5; // Изначальный радиус точки притяжения
	this.holeRadiusMax = 15 * this.spaceRadius * 0.01; // Максимальый радиус точки притяжения
	this.holeRadiusMin = 5 * this.spaceRadius * 0.01; // Минимальный радиус точки притяжения
	this.holeLimit = false; // Пределы точки притяжения 
	this.slice = 2 * Math.PI / (particlesCount - 1);
    this.x = ox;
	this.y = oy;
    this.startX = ox + (this.spaceRadius * Math.cos(this.slice * this.i));
	this.startY = oy + (this.spaceRadius * Math.sin(this.slice * this.i));
}

// Логика поведения частиц
newParticle.prototype.draw = function() {
    context.fillStyle = '#33DDFF';
	this.velocity += 3;
	this.x = ox + this.velocity * Math.cos(this.slice * this.i);
	this.y = oy + this.velocity * Math.sin(this.slice * this.i);

	if (this.x > this.startX + this.moveLimit || this.x < this.startX - this.moveLimit) 
		this.velocity *= -1;
	if (this.y > this.startY + this.moveLimit || this.y < this.startY - this.moveLimit) 
		this.velocity *= -1;

    context.beginPath();
    context.arc(this.x, this.y, this.radiusParticle, 0, 2 * Math.PI, false);
	context.fill();
	if (this.holeRadius <= this.holeRadiusMax && this.holeLimit == false) {
		this.holeRadius+=0.4;
		if (this.holeRadius >= this.holeRadiusMax) this.holeLimit = true;
    }
    if (this.holeRadius > this.holeRadiusMin && this.holeLimit == true) {
		this.holeRadius-=0.4;
		if (this.holeRadius <= this.holeRadiusMin) this.holeLimit = false;
    }
	context.arc(ox, oy, this.holeRadius, 0, 2 * Math.PI);
	context.fill();
}

// Создание частиц
function createnewParticle() {
    for (var i = 0; i < particlesCount; i++) new newParticle(i);
}

// Кроссплатформенность для функции 
window.requestAnimFrame = (function() { return window.requestAnimationFrame || 
											   window.webkitRequestAnimationFrame || 
											   window.mozRequestAnimationFrame})();

// Анимация
function draw() {
    requestAnimFrame(draw);
    context.clearRect(0, 0, canvas.width, canvas.height); // Очищаем канвас
    for (var i in particles) particles[i].draw(); // Рисуем
}

createnewParticle();
draw();