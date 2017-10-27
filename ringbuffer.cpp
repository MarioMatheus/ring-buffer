#include "ringbuffer.h"

RingBuffer::RingBuffer(unsigned int size):
    data() ,it(data.begin()), size_data(size),ctrlInsert(0), ctrlRemove(0){}

int & RingBuffer::operator [](int i){
    return data[i];
}

void RingBuffer::clear_data(){
    return data.clear();
}

bool RingBuffer::is_full(){
    return (data.size() == this->size_data ? true : false);
}

bool RingBuffer::is_empty(){
    return (data.size() == 0 ? true : false);
}

void RingBuffer::insert(int data){
    if(this->is_full()){
        this->data.erase(this->data.end()-1);
        this->it = this->data.begin();
    }
    this->it = this->data.insert(this->it++, data);
}

bool RingBuffer::remove(int data){
    for (unsigned i = 0; i < this->data.size(); i++){
        if(this->data.at(i) == data) {
            this->data.erase(this->data.begin()+i);
            return true;
        }
    }
    return false;
}

std::string RingBuffer::to_string(){
    std::string str;

    for(unsigned i = 0; i < data.size()-1; i++)
      str.append(std::to_string(data[i]) + " - ");

    str.append(std::to_string(data[data.size()-1]));
    return str;
}
