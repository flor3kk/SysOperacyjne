[bits 32]

; nasm mkdir.asm -o mkdir.o -f win32
; gcc mkdir.o -o mkdir.exe -m32

extern   _printf
extern   _scanf
extern   _exit
extern   _mkdir

section  .data
prompt   db "podaj nazwe: ", 0
format   db "%s", 0  ; do zapisania nazwy folderu
goodInfo  db "utworzylem folder '%s' ", 0xA, 0
badInfo db "nie udalo sie utworzyc", 0xA, 0

section  .bss
folderName:  resb 256 ; nazwa zmiennej i rezerwacja 256

section  .text
global   _main

_main:
         push prompt        ; [prompt][ret]
         call _printf
         add esp, 4         ; [ret]

         push folderName    ; [folderName][ret]
         push format        ; [format][folderName][ret]
         call _scanf
         add esp, 8         ; [ret]

         push folderName    ; [folderName][ret]
         call _mkdir        ; tworzy folder o podanej nazwie folderu
         add esp, 4         ; [ret]

         test eax, eax      ; ustawienie flagi zf = 1, jesl eax == 0
         jz good            ; skocz jesli zf = 1

         push badInfo       ; jesli eax == 1 to wtedy [badInfo][esp]
         call _printf
         add esp, 4         ; [ret]

         push 0             ; [0][ret]
         call _exit

good:
         push folderName    ; [folderName][ret]
         push goodInfo      ; [goodInfo][folderName][ret]
         call _printf
         add esp, 8         ; [ret]

         push 0             ; [0][ret]
         call _exit

