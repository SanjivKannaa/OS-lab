#include <iostream>
#include <string>

using namespace std;

class FileBlock {
public:
    string data;
    FileBlock* next_block;

    FileBlock(string data) {
        this->data = data;
        next_block = NULL;
    }
};

class LinkedFileAllocation {
public:
    FileBlock* start_block;

    LinkedFileAllocation() {
        start_block = NULL;
    }

    void allocate_block(string data) {
        FileBlock* new_block = new FileBlock(data);
        if (start_block == NULL) {
            start_block = new_block;
        } else {
            FileBlock* current_block = start_block;
            while (current_block->next_block != NULL) {
                current_block = current_block->next_block;
            }
            current_block->next_block = new_block;
        }
    }

    void delete_block(string data) {
        if (start_block == NULL) {
            cout << "The file is empty." << endl;
        } else if (start_block->data == data) {
            start_block = start_block->next_block;
        } else {
            FileBlock* current_block = start_block;
            while (current_block->next_block != NULL && current_block->next_block->data != data) {
                current_block = current_block->next_block;
            }
            if (current_block->next_block == NULL) {
                cout << "The block to delete is not found." << endl;
            } else {
                current_block->next_block = current_block->next_block->next_block;
            }
        }
    }
};

int main() {
    LinkedFileAllocation file;

    file.allocate_block("Block 1");
    file.allocate_block("Block 2");
    file.allocate_block("Block 3");

    cout << "File blocks:" << endl;
    FileBlock* current_block = file.start_block;
    while (current_block != NULL) {
        cout << current_block->data << endl;
        current_block = current_block->next_block;
    }

    file.delete_block("Block 2");

    cout << "File blocks after deleting Block 2:" << endl;
    current_block = file.start_block;
    while (current_block != NULL) {
        cout << current_block->data << endl;
        current_block = current_block->next_block;
    }

    return 0;
}
