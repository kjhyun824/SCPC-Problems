#include <iostream>
#include <list>

#define MIN(a, b) ((a < b) ? (a ): (b))
#define MAX(a, b) ((a > b) ? (a) : (b))
#define ABS(a) ((a > 0) ? (a) : -(a))

using namespace std;

class Battery {
	private:
		int x, y;
	public:
		Battery(int _x, int _y) {
			x = _x;
			y = _y;
		}
		int getX() { return x; }
		int getY() { return y; }
		int setX(int _x) { return (x=_x); }
		int setY(int _y) { return (y=_y); }
};

class Rod {
	private:
		int x1, y1;
		int x2, y2;
	public:
		Rod(int _x1, int _y1, int _x2, int _y2) {
			x1 = _x1 * 2;
			y1 = _y1 * 2;
			x2 = _x2 * 2;
			y2 = _y2 * 2;
		}
		int getPowerDistX(int b_x) { return (ABS(b_x - x1) < ABS(b_x - x2)) ? x1 : x2; }
		int getPowerDistY(int b_y) { return (ABS(b_y - y1) < ABS(b_y - y2)) ? y1 : y2; }
};

class Circuit {
	private:
		list<Rod*> rod;
		int n_rod;
		Battery *battery;
		int min_x, min_y, max_x, max_y;
		int best_max_dist_x, best_max_dist_y;
	public:
		Circuit(int _n_rod){
			n_rod = _n_rod;
			min_x = min_y = 2e9;
			max_x = max_y = 0;
			battery = new Battery(0, 0);
		}
		~Circuit(){
			for (list<Rod*>::iterator it=rod.begin(); it!=rod.end(); it++) {
				delete *it;
			}
			delete battery;
		}
		void load() {
			for (int i=0; i<n_rod; i++){
				int x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;
				rod.push_back(new Rod(x1, y1, x2, y2));
				min_x = MIN(min_x, MIN(x1, x2));
				min_y = MIN(min_y, MIN(y1, y2));
				max_x = MAX(max_x, MAX(x1, x2));
				max_y = MAX(max_y, MAX(y1, y2));
			}
		}
		// Since max(max(x,y)) = max(max(x), max(y)), find minimum power distance x and y separately.
		void calcOptimalPowerDist(int init_x, int init_y){
			int min_rod_x, max_rod_x, min_rod_y, max_rod_y;
			battery->setX(init_x);
			battery->setY(init_y);
			bool converge = false;
			while (!converge) {
				min_rod_x = min_rod_y = 2e9;
				max_rod_x = max_rod_y = 0;
				for (list<Rod*>::iterator it = rod.begin(); it != rod.end(); it++) {
					int rod_x = (*it)->getPowerDistX(battery->getX());
					int rod_y = (*it)->getPowerDistY(battery->getY());

					min_rod_x = MIN(min_rod_x, rod_x);
					max_rod_x = MAX(max_rod_x, rod_x);
					min_rod_y = MIN(min_rod_y, rod_y);
					max_rod_y = MAX(max_rod_y, rod_y);
				}
				int next_x = (min_rod_x + max_rod_x)/2;
				int next_y = (min_rod_y + max_rod_y)/2;

				if ((battery->getX() == next_x) && (battery->getY() == next_y)) {
					converge = true;
				} else {
					battery->setX(next_x);
					battery->setY(next_y);
				}
			}
			best_max_dist_x = max_rod_x - battery->getX();
			best_max_dist_y = max_rod_y - battery->getY();
		}

		int solve() {
			calcOptimalPowerDist(min_x, min_y);
			int x1 = best_max_dist_x, y1 = best_max_dist_y;
			calcOptimalPowerDist(max_x, max_y);
			int x2 = best_max_dist_x, y2 = best_max_dist_y;
			int x = MIN(x1, x2), y = MIN(y1, y2);

			return MAX(x, y);
		}
};

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		int n_rod;
		cin >> n_rod;
		Circuit circuit(n_rod);
		cout << "Case #" << test_case+1 << endl;
		circuit.load();
        int Answer = circuit.solve();
        if(Answer % 2 == 0)
            cout << (Answer >> 1) << endl;
        else
            cout << (Answer >> 1) << ".5" << endl;
	}
	return 0;
}
