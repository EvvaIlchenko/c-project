#include <iostream>
#include <json-c/json.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    json_object *jobj = json_object_new_object();
    json_object *jstring = json_object_new_string("Anastasia");
    json_object *jint = json_object_new_int(10);
    json_object *jboolean = json_object_new_boolean(0);

    json_object_object_add(jobj, "name", jstring);
    json_object_object_add(jobj, "age", jint);
    json_object_object_add(jobj, "married", jboolean);

    cout << json_object_to_json_string(jobj) << endl;

    return 0;
}
