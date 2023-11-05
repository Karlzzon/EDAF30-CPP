#include "editor.h"

#include <string>

using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const {
    int skip = 0;
    char match ='2';

    if (text[pos] == ')') {
        match = '(';
    } else if (text[pos] == ']') {
        match = '[';
    } else {
        match = '{';
    }


    for (int i = pos-1; i>0; i--){
        if (text[i] == text[pos]){
            skip++;
        } else if ((text[i] == match) && skip!=0) {
            skip--;
        } else if ((text[i] == match) && skip == 0) {
            return i;
        }
    }

    return string::npos;
}	
