class TextEditor {
private:
    string left,right;
    string get_last(){
        int len=min(10,(int)left.size());
        return left.substr(left.size()-len);
    }
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        left+=text;
    }
    
    int deleteText(int k) {
        int removed=min(k,(int)left.size());
        left.resize(left.size()-removed);
        return removed;
    }
    
    string cursorLeft(int k) {
        while(k>0 &&!left.empty()){
            right.push_back(left.back());
            left.pop_back();
            k--;
        }
        return get_last();
    }
    
    string cursorRight(int k) {
        while(k>0 &&!right.empty()){
            left.push_back(right.back());
            right.pop_back();
            k--;
        }
        return get_last();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */