#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <vector>
#include <string>
#include <ostream>

class RingBuffer
{
    public:
        RingBuffer(unsigned int size);  //constructor
        int & operator [](int i) ;      //operator [] overloading
        friend std::ostream& operator <<(std::ostream& os, const RingBuffer& rb){
                    std::string str;
                    for(unsigned i = 0; i < rb.data.size()-1; i++)
                      str.append(std::to_string(rb.data[i]) + " - ");
                    str.append(std::to_string(rb.data[rb.data.size()-1]));
                    os << str;
                    return os;
        };

        //general functions
        void insert(int data);          //for data insertion
        bool remove(int data);          //for data removal
        bool is_full();                 //check if buffer is already full
        bool is_empty();                //check if buffer is empty
        void clear_data();              //clear data :)
        std::string to_string();        //print vector data

    private:
        std::vector<int> data;          //buffer's data
        std::vector<int>::iterator it;  //iterator for vector control
        std::size_t size_data;          //contains the buffer size
        unsigned int ctrlInsert;        //insertion controller
        unsigned int ctrlRemove;        //removal controller
};

#endif // RINGBUFFER_H
