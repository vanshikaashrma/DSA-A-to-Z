/*Design a queuing system for a printer such that it can print only two pages of a job at a
time. For remaining pages, job has to wait in the queue till its next chance. You should be able
to display the list of the jobs waiting in the queue with number of pages left. (10 Marks)
For instance, J1-5 means job 1 with 5 pages to be printed:
J1-5; J2-3; J3-4
J2-3; J3-4; J1-3
J3-4; J1-3; J2-1
J1-3; J2-1; J3-2; J4-2
J2-1; J3-2; J4-2; J1-1
J3-2; J4-2; J1-1
J4-2; J1-1
J1-1 
*/


#include <iostream>
#include <string>

using namespace std;

class Job {
public:
    string jobName; // Job identifier (e.g., "J1")
    int pages;      // Number of pages to print
    Job* next;     // Pointer to the next job

    Job(string name, int p) : jobName(name), pages(p), next(nullptr) {}
};

class PrinterQueue {
private:
    Job* front; // Pointer to the front of the queue
    Job* rear;  // Pointer to the rear of the queue
    int size;   // Number of jobs in the queue

public:
    PrinterQueue() : front(nullptr), rear(nullptr), size(0) {}

    ~PrinterQueue() {
        while (front != nullptr) {
            Job* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void addJob(const string& jobName, int pages) {
        Job* newJob = new Job(jobName, pages);
        if (rear == nullptr) { // Queue is empty
            front = rear = newJob;
        } else {
            rear->next = newJob; // Link new job to the end
            rear = newJob;       // Update rear
        }
        size++;
    }

    void printJobs() {
        cout << "Current queue: ";
        Job* temp = front;
        while (temp != nullptr) {
            cout << temp->jobName << "-" << temp->pages << "; ";
            temp = temp->next;
        }
        cout << endl;
    }

    void processJobs() {
        while (front != nullptr) {
            Job* currentJob = front; // Get the job at the front of the queue
            int pagesToPrint = min(currentJob->pages, 2); // Print up to 2 pages

            cout << "Printing " << pagesToPrint << " pages of " << currentJob->jobName << endl;

            // Update the job's pages
            currentJob->pages -= pagesToPrint;
            if (currentJob->pages == 0) {
                // If no pages are left, remove the job from the queue
                front = front->next; // Move front pointer to the next job
                delete currentJob; // Free memory
            } else {
                // If there are pages left, keep it in the queue
                front = front->next; // Move front pointer
                addJob(currentJob->jobName, currentJob->pages); // Re-add job to the end
                delete currentJob; // Free the old job node
            }
            printJobs(); // Display the current state of the queue
        }
    }
};

int main() {
    PrinterQueue printerQueue;

    // Adding jobs to the printer queue
    printerQueue.addJob("J1", 5);
    printerQueue.addJob("J2", 3);
    printerQueue.addJob("J3", 4);

    // Process the jobs in the queue
    printerQueue.processJobs();

    return 0;
}
