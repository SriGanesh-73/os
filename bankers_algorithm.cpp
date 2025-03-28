#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BankersAlgorithm {
    int processes, resources;
    vector<vector<int>> allocation, max, need;
    vector<int> available;

public:
    BankersAlgorithm(int p, int r) {
        processes = p;
        resources = r;

        allocation.resize(p, vector<int>(r));
        max.resize(p, vector<int>(r));
        need.resize(p, vector<int>(r));
        available.resize(r);

        cout << "Enter the Allocation Matrix: \n";
        for (int i = 0; i < processes; i++) {
            for (int j = 0; j < resources; j++) {
                cin >> allocation[i][j];
            }
        }

        cout << "Enter the Max Matrix: \n";
        for (int i = 0; i < processes; i++) {
            for (int j = 0; j < resources; j++) {
                cin >> max[i][j];
            }
        }

        cout << "Enter the Available Resources: \n";
        for (int i = 0; i < resources; i++) {
            cin >> available[i];
        }

        for (int i = 0; i < processes; i++) {
            for (int j = 0; j < resources; j++) {
                need[i][j] = max[i][j] - allocation[i][j];
            }
        }
    }

    bool isSafe() {
        vector<bool> finish(processes, false);
        vector<int> work = available;
        int count = 0;

        while (count < processes) {
            bool progressMade = false;

            for (int i = 0; i < processes; i++) {
                if (!finish[i]) {
                    bool canFinish = true;

                    for (int j = 0; j < resources; j++) {
                        if (need[i][j] > work[j]) {
                            canFinish = false;
                            break;
                        }
                    }

                    if (canFinish) {
                        for (int j = 0; j < resources; j++) {
                            work[j] += allocation[i][j];
                        }

                        finish[i] = true;
                        count++;
                        progressMade = true;
                        break;
                    }
                }
            }

            if (!progressMade) {
                return false;
            }
        }
        return true;
    }

    void requestResources(int process, vector<int> request) {
        for (int i = 0; i < resources; i++) {
            if (request[i] > need[process][i]) {
                cout << "Error: Process has exceeded maximum claim.\n";
                return;
            }
            if (request[i] > available[i]) {
                cout << "Resources are not available.\n";
                return;
            }
        }

        vector<int> originalAvailable = available;
        vector<vector<int>> originalAllocation = allocation;
        vector<vector<int>> originalNeed = need;

        for (int i = 0; i < resources; i++) {
            available[i] -= request[i];
            allocation[process][i] += request[i];
            need[process][i] -= request[i];
        }

        if (isSafe()) {
            cout << "Request granted.\n";
        } else {
            cout << "Request denied.\n";
            available = originalAvailable;
            allocation = originalAllocation;
            need = originalNeed;
        }
    }
};

int main() {
    int p, r;
    cout << "Enter number of processes and resources: ";
    cin >> p >> r;

    BankersAlgorithm ba(p, r);

    vector<int> request(r);
    int process;

    cout << "Enter process number and resource request: ";
    cin >> process;
    for (int i = 0; i < r; i++) {
        cin >> request[i];
    }

    ba.requestResources(process, request);

    return 0;
}

