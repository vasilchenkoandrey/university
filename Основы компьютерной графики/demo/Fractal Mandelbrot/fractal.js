window.onload = function() {
    // Метод document.getElementById() возвращает ссылку на элемент, который имеет атрибут id с указанным значением.
    var canvas = document.getElementById("idcanvas");
    //Метод HTMLCanvasElement.getContext() возвращает контекст рисования на холсте
    var context = canvas.getContext("2d");
    
    // Ширина и высота рисунка
    var imgWidth = canvas.width;
    var imgHeight = canvas.height;
    
    // Метод createImageData() создает новый, пустой объект ImageData. Пиксели нового объекта по умолчанию имеют значение прозрачного черного цвета.
    var imagedata = context.createImageData(imgWidth, imgHeight);
    
    // Параметры панорамирования и масштабирования
    var offsetx = -imgWidth/2;
    var offsety = -imgHeight/2;
    var panx = -100;
    var pany = 0;
    var zoom = 150;
    
    // Палитра. Массив из 256 цветов
    var palette = [];
    
    // Максимальное число итераций на пиксель
    var maxiterations = 200;
    
    // Инициализация
    function init() {
        // Событие мыши
        canvas.addEventListener("mousedown", onMouseDown);
        
        // Создаём палитру
        generatePalette();
        
        // Создаём изображение
        generateImage();
    
        // Основной цикл
        main(0);
    }
    
    // Основной цикл
    function main(tframe) {
        // window.requestAnimationFrame указывает браузеру на то, что вы хотите произвести анимацию, и просит его запланировать перерисовку на следующем кадре анимации.
        window.requestAnimationFrame(main);
        
        // Метод putImageData() помещает данные изображения (из заданного объекта ImageData) обратно на холст.
        context.putImageData(imagedata, 0, 0);
    }
    
    // Палитра
    function generatePalette() {
        // Вычисляем градиент
        var roffset = 24;
        var goffset = 16;
        var boffset = 0;
        for (var i=0; i<256; i++) {
            palette[i] = { r:roffset, g:goffset, b:boffset};
            
            if (i < 64) {
                roffset += 3;
            } else if (i<128) {
                goffset += 3;
            } else if (i<192) {
                boffset += 3;
            }
        }
    }
    
    // Генерируем фрактал
    function generateImage() {
        // Итерации попиксельно
        for (var y=0; y<imgHeight; y++) {
            for (var x=0; x<imgWidth; x++) {
                iterate(x, y, maxiterations);
            }
        }
    }

    // Вычисляем цвет определенного пикселя
    function iterate(x, y, maxiterations) {
        // Преобразование координаты экрана в фрактальную координату
        var x0 = (x + offsetx + panx) / zoom;
        var y0 = (y + offsety + pany) / zoom;
        
        // Переменные итерации
        var a = 0;
        var b = 0;
        var rx = 0;
        var ry = 0;
        
        // Итерации
        var iterations = 0;
        while (iterations < maxiterations && (rx * rx + ry * ry <= 4)) {
            rx = a * a - b * b + x0;
            ry = 2 * a * b + y0;
            
            // Следующая итерация
            a = rx;
            b = ry;
            iterations++;
        }
        
        // Получаем цвет палитры на основе количества итераций
        var color;
        if (iterations == maxiterations) {
            color = { r:0, g:0, b:0}; // Черный цвет
        } else {
            var index = Math.floor((iterations / (maxiterations-1)) * 255);
            color = palette[index];
        }
        
        // Применяем цвет
        var pixelindex = (y * imgWidth + x) * 4;
        imagedata.data[pixelindex] = color.r;
        imagedata.data[pixelindex+1] = color.g;
        imagedata.data[pixelindex+2] = color.b;
        imagedata.data[pixelindex+3] = 255;
    }
    
    // Увеличение фрактала
    function zoomFractal(x, y, factor, zoomin) {
        if (zoomin) {
            // Увеличить
            zoom *= factor;
            panx = factor * (x + offsetx + panx);
            pany = factor * (y + offsety + pany);
        } else {
            // Уменьшить
            zoom /= factor;
            panx = (x + offsetx + panx) / factor;
            pany = (y + offsety + pany) / factor;
        }
    }
    
    // Обработчики событий мыши
    function onMouseDown(e) {
        var pos = getMousePos(canvas, e);
        
        // Уменьшение масштаба с зажатой клавишей Ctrl
        var zoomin = true;
        if (e.ctrlKey) {
            zoomin = false;
        }
        
        // Перемещение с зажатой клавишей Shift
        var zoomfactor = 2;
        if (e.shiftKey) {
            zoomfactor = 1;
        }
        
        // Увеличение фрактала в положении мыши
        zoomFractal(pos.x, pos.y, zoomfactor, zoomin);
        
        // Отрисовываем фрактал
        generateImage();
    }
    
    // Получаем положение мыши
    function getMousePos(canvas, e) {
        var rect = canvas.getBoundingClientRect();
        return {
            x: Math.round((e.clientX - rect.left)/(rect.right - rect.left)*canvas.width),
            y: Math.round((e.clientY - rect.top)/(rect.bottom - rect.top)*canvas.height)
        };
    }
    
    // Инициализируем
    init();
};