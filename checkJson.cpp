#include <iostream> //підключаємо бібліотеки
#include <json-c/json.h>

using namespace std; //підключаємо простір імен

int main()  // оголошення початкової функції
{
    cout << "Hello world!" << endl; //виведення рядка "Hello world!" в консоль.

//Створення об'єкта json_object з іменем jobj. 
//Це відповідає кореневому об'єкту JSON.
    json_object *jobj = json_object_new_object();

//Створення об'єктів jstring, jint та jboolean з відповідною інформацією.
    json_object *jstring = json_object_new_string("Anastasia");
    json_object *jint = json_object_new_int(10);
    json_object *jboolean = json_object_new_boolean(0);

    json_object_object_add(jobj, "name", jstring);
    json_object_object_add(jobj, "age", jint);
    json_object_object_add(jobj, "married", jboolean);

//Виведення у консоль JSON-рядка, який представляє об'єкт jobj.
//Функція json_object_to_json_string використовується для перетворення об'єкта json_object
//в його JSON-рядкове представлення.
    cout << json_object_to_json_string(jobj) << endl;

    return 0;
}
