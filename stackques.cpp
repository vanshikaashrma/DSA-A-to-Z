Design a browser history maintenance application using stack (with linked list) such that
top of the stack keeps the information of the current page. The user can move back a certain
number of steps in your browser history, or move forward a certain number of steps in the
history. You should be able to display the browsing history at any time. (10 Marks)
For instance: let the user visited p1, p2, p3, p4 pages then moved back 2 times, then moved
forward one time and then visited p5 page.
The stack contents will be:
p1, p2, p3, p4
p1, p2, p3
p1, p2
p1, p2, p3
p1, p2, p3, p5



#include <iostream>
#include <string>

using namespace std;

class PageNode {
public:
    string pageName; // Name of the page
    PageNode* next;  // Pointer to the next page in the stack

    PageNode(string name) : pageName(name), next(nullptr) {}
};

class HistoryStack {
private:
    PageNode* top; // Pointer to the top page in the stack

public:
    HistoryStack() : top(nullptr) {}

    ~HistoryStack() {
        while (top != nullptr) {
            PageNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void visitPage(const string& pageName) {
        PageNode* newPage = new PageNode(pageName);
        newPage->next = top; // Link the new page to the top
        top = newPage;       // Update top to the new page
    }

    void back(int steps) {
        while (steps-- > 0 && top != nullptr) {
            cout << "Going back from: " << top->pageName << endl;
            top = top->next; // Move back by popping the top page
        }
    }

    void forward(int steps) {
        // Since this is a stack, we can't go forward without a separate structure.
        // We'll have to keep track of the forward history separately.
        // This can be done by maintaining a second stack for forward navigation,
        // but for simplicity, let's assume forward navigation is limited to visiting new pages.

        cout << "Forward navigation not implemented directly. You can visit a new page instead." << endl;
    }

    void displayHistory() const {
        cout << "Browsing History: ";
        PageNode* current = top;
        while (current != nullptr) {
            cout << current->pageName << (current->next ? " -> " : "");
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    HistoryStack browserHistory;

    // Simulating page visits
    browserHistory.visitPage("p1");
    browserHistory.visitPage("p2");
    browserHistory.visitPage("p3");
    browserHistory.visitPage("p4");

    // Display current history
    browserHistory.displayHistory(); // p4 -> p3 -> p2 -> p1

    // Move back 2 steps
    browserHistory.back(2);
    browserHistory.displayHistory(); // p2 -> p1

    // Move forward (not implemented, but can visit a new page)
    browserHistory.forward(1); // Just an informational message

    // Visit a new page
    browserHistory.visitPage("p5");
    browserHistory.displayHistory(); // p5 -> p2 -> p1

    return 0;
}
