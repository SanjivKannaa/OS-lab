#include <iostream>
#include <string>

using namespace std;

class FileAllocationTable {
public:
    int* table;
    int table_size;

    FileAllocationTable(int size) {
        table_size = size;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
    }

    void allocate_blocks(string filename, int start_block, int num_blocks) {
        for (int i = start_block; i < start_block + num_blocks; i++) {
            if (table[i] != -1) {
                cout << "Error: Block " << i << " is already allocated to another file." << endl;
                return;
            }
        }
        for (int i = start_block; i < start_block + num_blocks; i++) {
            table[i] = filename.size();
        }
        cout << "Allocated " << num_blocks << " blocks to file " << filename << "." << endl;
    }

    void delete_blocks(string filename) {
        for (int i = 0; i < table_size; i++) {
            if (table[i] == filename.size()) {
                table[i] = -1;
            }
        }
        cout << "Deleted all blocks of file " << filename << "." << endl;
    }

    void print_table() {
        for (int i = 0; i < table_size; i++) {
            if (i % 10 == 0) {
                cout << endl;
            }
            if (table[i] == -1) {
                cout << ".";
            } else {
                cout << table[i];
            }
        }
        cout << endl;
    }
};

int main() {
    int table_size;
    cout << "Enter the size of the file allocation table: ";
    cin >> table_size;
    FileAllocationTable table(table_size);

    while (true) {
        cout << endl;
        cout << "1. Allocate blocks to a file" << endl;
        cout << "2. Delete blocks of a file" << endl;
        cout << "3. Print file allocation table" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string filename;
            int start_block, num_blocks;
            cout << "Enter the name of the file: ";
            cin >> filename;
            cout << "Enter the starting block number: ";
            cin >> start_block;
            cout << "Enter the number of blocks to allocate: ";
            cin >> num_blocks;
            table.allocate_blocks(filename, start_block, num_blocks);
        } else if (choice == 2) {
            string filename;
            cout << "Enter the name of the file: ";
            cin >> filename;
            table.delete_blocks(filename);
        } else if (choice == 3) {
            table.print_table();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
