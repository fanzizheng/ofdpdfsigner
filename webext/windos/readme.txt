
sc create webext binPath=”C:\ofdreader\webext.exe“
sc config webext start= AUTO
net start webext

net stop webext

sc delete webext


