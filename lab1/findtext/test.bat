set PROGRAM="%~1"

rem проверяем поиск в пустом файле
%PROGRAM% empty.txt "you"
if NOT ERRORLEVEL 1 goto err

rem проверяем поиск в одной строке
%PROGRAM% oneline.txt "you"
if ERRORLEVEL 1 goto err

rem проверяем поиск в обычном тексте с множеством строк
%PROGRAM% multiline.txt "you"
if ERRORLEVEL 1 goto err

rem ожидаем ненулевой код ошибки при поиске в несуществующем файле
%PROGRAM% non-existing-file-name.txt "you"
if NOT ERRORLEVEL 1 goto err

rem проверяем поиск несуществующей строки в файле
%PROGRAM% multiline.txt "hi"
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1