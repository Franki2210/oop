set PROGRAM="%~1"

rem �������� ����������� ���������� �����
%PROGRAM% 6 > %TEMP%\output
fc.exe %TEMP%\output trueResult.txt
if ERRORLEVEL 1 goto err

rem �������� �� ����� �� ��������� 0..255
%PROGRAM% 266
if NOT ERRORLEVEL 0 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1