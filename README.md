![preview](preview.jpg)

# Библиотека для микроконтроллеров AVR для подключения экранов от телефонов Nokia

>**Более подробно о подключении экранов и библиотеке:**
>- [Подключение дисплея от Nokia 1100. Часть 1.](https://digitalchip.ru/podklyuchenie-displeya-ot-nokia-1100-chast-1/)
>- [Подключение дисплея от Nokia 1100. Часть 2.](https://digitalchip.ru/podklyuchenie-displeya-ot-nokia-1100-chast-2/)
>- [Работаем с дисплеем от Nokia 1100 в графическом режиме](https://digitalchip.ru/rabotaem-s-displeem-ot-nokia-1100-v-graficheskom-rezhime/)
>- [Описание функций графической библиотеки для LCD-экрана от Nokia 1100](http://digitalchip.ru/opisanie-funktsiy-graficheskoy-biblioteki-dlya-lcd-ekrana-ot-nokia-1100)
>- [Подключение дисплеев Nokia](https://digitalchip.ru/podklyuchenie-displeev-nokia-1110-1110i-1200-1202-1203-1112-1116-2660-2760-6085/)

## Поддерживаемые экраны
Поддерживаеются экраны от телефонов Nokia 1110/1110i/1200/1202/1203/1112/1116/2660/2760/6085. 
Т.е. экраны, которые управляются контроллером PCF8814.


## Варианты и версии библиотеки
На данный момент существует 2 варианта библиотечки - текстовый и графический варианты.

Текстовый вариант библиотеки имеет нумерацию 1.x и содержит только функции вывода на экран текстовой информации. Преимущество данного варианта в том, что он занимает в памяти программ минимум места и не создает никаких буферов в оперативной памяти. Содержит только функции вывода текста на экран. Рекомендуется для микроконтроллеров AVR с минимумом системных ресурсов (программной и оперативной памяти).

Второй вариант библиотеки — графический. Имеет нумерацию 2.x и содержит весь набор функций текстового варианта с добавлением функций для работы с графикой. В отличии от текстового варианта занимает намного больше памяти, как программной, так и оперативной. В оперативной памяти создается видеобуфер, содержащий копию того, что выведено на экран, так как дисплеи от Nokia позволяют только записывать данные в контроллер дисплея (хотя сам контроллер позволяет как записывать, так и читать данные). Буфер занимает в памяти 864 байта, плюс еще несколько переменных. Соответственно, применять этот вариант библиотеки можно на микроконтроллерах, которые имеют достаточное количество оперативной памяти.

## Краткое описание функций графической библиотеки

`void nlcd_Init(void);`

Инициализация контроллера PCF8814, очистка экрана, инициализация библиотеки.

___

`void nlcd_Clear(void);`

Очистка экрана. Очищает экран (и видеобуфер) и устанавливает текущие координаты в нулевые координаты (левый верхний угол).

___

`void nlcd_SendByte(char mode,unsigned char c);`

Отправляет байт в контроллер PCF8814. Если передаются данные, то они также сохраняются в видеобуфере.

**Параметры:**

- `mode:`
    - `CMD_LCD_MODE` — передается команда контроллеру
    - `DATA_LCD_MODE` — передаются данные
- `с`: передаваемый байт

___

`void nlcd_Putc(unsigned char c);`

Выводит знак с кодом `C` в текущее место

___

`void nlcd_Print(char * message);`

Выводит строку символов из оперативной памяти, начиная с текущего знакоместа.

___

`void nlcd_PrintF(unsigned char * message);`

Выводит строку символов из программной памяти, начиная с текущего знакоместа.

___

`void nlcd_GotoXY(char x,char y);`

Устанавливает текущие координаты. Отсчет идет в знакоместах 5×8.

**Параметры:**

- `x`: 0..15 — координата по оси X
- `y`: 0..7 — координата по оси Y

___

`void nlcd_Inverse(unsigned char mode);`

Устанавливает режим инверсии для всего экрана.

**Параметры:**

- `mode`:
  - `INV_MODE_ON` — инверсия включена
  - `INV_MODE_OFF` — инверсия выключена

___

`void nlcd_Pixel (unsigned char x,unsigned char y, unsigned char pixel_mode);`

Выводит пиксель в указанные координаты.

**Параметры:**

- `x`: 0..95 — координата по оси X
- `y`: 0..64 — координата по оси Y
Отсчет ведется от верхнего левого угла.
- `pixel_mode`:
  - `PIXEL_ON` — пиксель устанавливается
  - `PIXEL_OFF` — пиксель сбрасывается (стирается)
  - `PIXEL_INV` — пиксель инвертируется

___

`void nlcd_Line (unsigned char x1,unsigned char y1, unsigned char x2,unsigned char y2, unsigned char pixel_mode);`

Рисует линию. Линия рисуется из точки с координатами x1, y1 в точку с координатами x2,y2.

**Параметры:**

- `x1, x2`: 0..95
- `y1,y2`: 0..64
- `pixel_mode`:
  - `PIXEL_ON` — пиксель устанавливается
  - `PIXEL_OFF` — пиксель сбрасывается (стирается)
  - `PIXEL_INV` — пиксель инвертируется

___

`void nlcd_Circle(unsigned char x, unsigned char y, unsigned char radius, unsigned char fill, unsigned char pixel_mode);`

Рисует закрашенную или нет окружность с координатами центра x, y и радиусом radius.

**Параметры:**

- `x`: 0..95
- `y`: 0..64
- `fill`:
  - `FILL_ON` — заливка выполняется
  - `FILL_OFF` — заливка не выполняется
- `pixel_mode`:
  - `PIXEL_ON` — пиксель устанавливается
  - `PIXEL_OFF` — пиксель сбрасывается (стирается)
  - `PIXEL_INV` — пиксель инвертируется

___

`void nlcd_Rect (unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char fill, unsigned char pixel_mode);`

Рисует прямоугольник. Пары значений x1, y1 и x2, y2 задают координаты противоположных углов по диагонали. Прямоугольник может иметь заливку.

**Параметры:**

- `x1, x2`: 0..95
- `y1, y2`: 0..64
- `fill`:
  - `FILL_ON` — заливка выполняется
  - `FILL_OFF` — заливка не выполняется
- `pixel_mode`:
  - `PIXEL_ON` — пиксель устанавливается
  - `PIXEL_OFF` — пиксель сбрасывается (стирается)
  - `PIXEL_INV` — пиксель инвертируется
