#include <iostream>
#include <vector>
struct Task {
    int pri, num;
};
int main() {
	int n;
	std::cin >> n;
	while (n--) {
		int n, m, l;
		Task j;
		std::cin >> n >> m;
		std::vector<Task> job;
		for (int i = 0; i < n; i++) {
			std::cin >> l;
			j.num = i;
			j.pri = l;
			job.push_back(j);
		}
		int time = 0;
		while (!job.empty()) {
			Task head = job.front();
			int length  = job.size();
			int flag = 0;
			for (int i = 0; i < length; i++) {
                if (head.pri < job[i].pri) {
                    job.push_back(head);
                    flag = 1;
                    break;
                }
            }
            job.erase(job.begin());
            if (flag == 0) time++;
            if (flag == 0 && head.num == m) break;
        }
        std::cout << time << std::endl;
    }
    return 0;
}
