# c-project

Підключення бібліотеки json-c
Якщо на вашому диску є папка "msys64", запустіть "С:\msys64\mingw64.exe"
Далі у командному рядку треба написати "pacman -S mingw-w64-x86_64-json-c mingw-w64-x86_64-gcc" (з точністю до усіх пробілів). Далі чекаємо поки все загрузиться.
тепер маємо підключити цю бібліотеку до нашого середовища. Я пишу у кодблокс.
Щоб підключити json у codeblocks:
клацніть правою кнопкою мишки по проекту
Далі build options -> linker settings -> add -> *вказуємо шлях до завантаженої бібліотеки*
