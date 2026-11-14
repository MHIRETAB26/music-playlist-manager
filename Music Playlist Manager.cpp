#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    Song* next;
    Song* prev;
};

Song* head = NULL;
Song* current = NULL;

/* =========================
   CREATE SONG NODE
========================= */
Song* createSong() {
    Song* newSong = new Song;

    cout << "\nEnter song title: ";
    cin.ignore();
    getline(cin, newSong->title);

    cout << "Enter artist name: ";
    getline(cin, newSong->artist);

    newSong->next = NULL;
    newSong->prev = NULL;

    return newSong;
}

/* =========================
   ADD SONG
========================= */
void addSong() {
    Song* newSong = createSong();

    if (head == NULL) {
        head = newSong;
        current = head;
    } else {
        Song* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->prev = temp;
    }

    cout << "Song added successfully!\n";
}

/* =========================
   DISPLAY PLAYLIST
========================= */
void displayPlaylist() {
    if (head == NULL) {
        cout << "\nPlaylist is empty!\n";
        return;
    }

    Song* temp = head;
    int i = 1;

    cout << "\n?? PLAYLIST ??\n";
    while (temp != NULL) {
        cout << i << ". " << temp->title << " - " << temp->artist << endl;
        temp = temp->next;
        i++;
    }
}

/* =========================
   DELETE SONG
========================= */
void deleteSong() {
    if (head == NULL) {
        cout << "\nPlaylist is empty!\n";
        return;
    }

    string key;
    cout << "\nEnter song title to delete: ";
    cin.ignore();
    getline(cin, key);

    Song* temp = head;

    while (temp != NULL && temp->title != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Song not found!\n";
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    } 
    else {
        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Song deleted successfully!\n";
}

/* =========================
   NEXT SONG
========================= */
void nextSong() {
    if (current == NULL) {
        cout << "\nPlaylist is empty!\n";
        return;
    }

    if (current->next != NULL) {
        current = current->next;
        cout << "\n? Now Playing: " << current->title
             << " - " << current->artist << endl;
    } else {
        cout << "\nAlready at last song.\n";
    }
}

/* =========================
   PREVIOUS SONG
========================= */
void prevSong() {
    if (current == NULL) {
        cout << "\nPlaylist is empty!\n";
        return;
    }

    if (current->prev != NULL) {
        current = current->prev;
        cout << "\n? Now Playing: " << current->title
             << " - " << current->artist << endl;
    } else {
        cout << "\nAlready at first song.\n";
    }
}

/* =========================
   MAIN MENU
========================= */
int main() {
    int choice;

    do {
        cout << "\n==================================";
        cout << "\n *MUSIC PLAYLIST MANAGER* ";
        cout << "\n==================================";
        cout << "\n1. Add Song";
        cout << "\n2. Delete Song";
        cout << "\n3. Display Playlist";
        cout << "\n4. Next Song";
        cout << "\n5. Previous Song";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addSong(); break;
            case 2: deleteSong(); break;
            case 3: displayPlaylist(); break;
            case 4: nextSong(); break;
            case 5: prevSong(); break;
            case 6: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
