bool kurungSeimbang(const string& ekspresi) {
    Stack s;
    inisialisasi(s);

    for (char karakter : ekspresi) {
        if (karakter == '(') {
            push(s, '(');
        }
        else if (karakter == '[') {
             push(s, '[');
        }
        else if (karakter == '{') {
            push(s, '{');
        }

        else if (karakter == ')' || 
                 karakter == ']' || 
                 karakter == '}') {

            int nilai;
 if (!pop(s, nilai)) {
                return false;
            }

            if (karakter == ')' && nilai != '(') {
                clear(s);
                return false;
            }

            if (karakter == ']' && nilai != '[') {
                clear(s);
                return false;
 }

            if (karakter == '}' && nilai != '{') {
                clear(s);
                return false;
            }
        }
    }

    bool seimbang = isEmpty(s);

    clear(s);

    return seimbang;
}
