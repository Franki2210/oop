set PROGRAM="%~1"

rem ��������� ����� � ������ �����
%PROGRAM% empty.txt "you"
if NOT ERRORLEVEL 1 goto err

rem ��������� ����� � ����� ������
%PROGRAM% oneline.txt "you" > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt trueResultOneLine.txt
if ERRORLEVEL 1 goto err

rem ��������� ����� � ������� ������ � ���������� �����
%PROGRAM% multiline.txt "you" > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt trueResultMultiline.txt
if ERRORLEVEL 1 goto err

rem ������� ��������� ��� ������ ��� ������ � �������������� �����
%PROGRAM% non-existing-file-name.txt "you"
if NOT ERRORLEVEL 1 goto err

rem ��������� ����� �������������� ������ � �����
%PROGRAM% multiline.txt "hi"
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1