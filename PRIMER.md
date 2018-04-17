# PRIMER

## Hoe werkt argument passing naar functions? 
Zie: https://en.wikipedia.org/wiki/X86_calling_conventions
Ligt aan je OS / compiler.
GCC passt arguments via de volgende registers: RDI, RSI, RDX, RCX, R8, R9, XMM0–7.
De functie stopt de return value in RAX.


## Hoe zit het met die register namen?
Kijk hier: https://docs.microsoft.com/en-us/windows-hardware/drivers/debugger/x64-architecture
De bepaalde onderdelen van de registers hebben ook weer eigen namen, bijvoorbeeld: de lage 32-bits van rax heet eax.
Er zit wel zekere logica in. Die logica kan je zelf wel uitvogelen.


## Hoe werkt assembly?
Kijk hier: http://www.felixcloutier.com/x86/


## Hoe werkt gdb? 
- Maak je leven makkelijker: installeer gdb-peda: https://github.com/longld/peda

- Met `info functions` krijg je een lijst te zien van functies en hun addressen

- Met disass adres/functienaam krijg je de disassembly te zien van die functie. Bijvoorbeeld: `disass main`. Dit disassemblet de main functie.

- Ewwww. Het gebruikt die vieze onleesbare AT&T syntax. Hoe verander ik mijn instellingen naar de superieure intel syntax? `set disassembly-flavor intel`.
Beter: zet het in je ~/.gdbinit.

- Als je in de disassembly een interessante plek hebt gevonden om een breakpoint neer te zetten. Dan kan je dit doen met b *adres,
bijvoorbeeld: b *0x400590.

- Met x/x100 $rsp kan je de een groot deel van de stack weergeven: handig om te zien waar je input terecht komt en waar interessante waardes staan.


## Ik wil specifieke bytes gebruiken in mijn exploit, maar er zit geen knop voor op mijn toetsenbord. Wat nu? 
Gebruik python!
Bijvoorbeeld:
python -c "print('A'*42 + '\x01\x02\x03\x04')"

Je kan dit direct doorsturen als input oor het programma:
python -c "print('A'*42 + '\x01\x02\x03\x04')" | ./challenge

Of je kan het schrijven naar een file om later te gebruiken:
python -c "print('A'*42 + '\x01\x02\x03\x04')" > exploit.bin

Let erop dat python's print() een '\xA' oftewel een line feed toevoegt aan het einde van de string.
Als dit een probleem is kan je het oplossen door python3 te gebruiken en aan print de extra parameter end='' mee te geven.


## Ik heb een exploit gemaakt en naar een file geschreven. Hoe gebruik ik hem?
Lokaal:
	cat exploit.bin - | ./challenge

Remote:
	cat exploit.bin - | nc [ip] [port]

Die - is voor als je een shell wil krijgen. Zonder de - sluit stdin en verlies je je shell meteen weer.
(De - vertelt cat om na exploit te printen verder te lezen uit stdin en dat te printen.)

Je kan je exploit bekijken door het te pipen naar xxd (een hexviewer).

## Ik probeer een specifieke waarde in het geheugen te zetten maar hij komt verkeerd om. Wat?
Dat is omdat het systeem little endian is.
Zie: https://en.wikipedia.org/wiki/Endianness

Als je de waarde 0x12345678 ergens in het geheugen wil zetten moet je dat dus doen als volgt:
python -c "print('A'*42 + '\x78\x56\x34\x12)"


## Heb je nog meer handige links?
Ja, deze bijvoorbeeld:
https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf


## Ik vind deze dingen leuk om mee bezig te zijn. Is er meer?
Neem contact met me op.