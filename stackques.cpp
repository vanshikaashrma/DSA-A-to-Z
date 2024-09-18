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

    void push(const string& pageName) {
        PageNode* newPage = new PageNode(pageName);
        newPage->next = top;
        top = newPage;
    }

    string pop() {
        if (top == nullptr) return ""; // Empty stack
        string pageName = top->pageName;
        PageNode* temp = top;
        top = top->next;
        delete temp;
        return pageName;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    string peek() const {
        return top ? top->pageName : "";
    }

    void display() const {
        PageNode* current = top;
        while (current != nullptr) {
            cout << current->pageName << (current->next ? " -> " : "");
            current = current->next;
        }
        cout << endl;
    }
};

class BrowserHistory {
private:
    HistoryStack backStack;   // Stack for back navigation
    HistoryStack forwardStack; // Stack for forward navigation
    string currentPage;      // Current page

public:
    void visitPage(const string& pageName) {
        if (!currentPage.empty()) {
            backStack.push(currentPage); // Push current page onto back stack
        }
        currentPage = pageName; // Set the new current page
        forwardStack = HistoryStack(); // Clear forward stack when visiting a new page
    }

    void back(int steps) {
        while (steps-- > 0 && !backStack.isEmpty()) {
            forwardStack.push(currentPage); // Push current page onto forward stack
            currentPage = backStack.pop(); // Move back
        }
    }

    void forward(int steps) {
        while (steps-- > 0 && !forwardStack.isEmpty()) {
            backStack.push(currentPage); // Push current page onto back stack
            currentPage = forwardStack.pop(); // Move forward
        }
    }

    void displayHistory() const {
        cout << "Back History: ";
        backStack.display();
        cout << "Current Page: " << currentPage << endl;
        cout << "Forward History: ";
        forwardStack.display();
    }
};

int main() {
    BrowserHistory browser;

    // Simulating page visits
    browser.visitPage("p1");
    browser.visitPage("p2");
    browser.visitPage("p3");
    browser.visitPage("p4");
    browser.displayHistory(); // Show current state

    // Move back 2 steps
    browser.back(2);
    browser.displayHistory(); // Show current state

    // Move forward 1 step
    browser.forward(1);
    browser.displayHistory(); // Show current state

    // Visit a new page
    browser.visitPage("p5");
    browser.displayHistory(); // Show current state

    return 0;
}
