#include <iostream>
#include <list>

#define MIN(a, b) ((a < b) ? (a ): (b))
#define MAX(a, b) ((a > b) ? (a) : (b))
#define ABS(a) ((a > 0) ? (a) : -(a))

using namespace std;

class Battery {
	private:
		double x, y;
	public:
		Battery(double _x, double _y) {
			x = _x;
			y = _y;
		}
		double getX() { return x; }
		double getY() { return y; }
		double setX(double _x) { return (x=_x); }
		double setY(double _y) { return (y=_y); }
};

class Rod {
	private:
		double x1, y1;
		double x2, y2;
	public:
		Rod(double _x1, double _y1, double _x2, double _y2) {
			x1 = _x1;
			y1 = _y1;
			x2 = _x2;
			y2 = _y2;
		}
		double getPowerDistX(double b_x) { return (ABS(b_x - x1) < ABS(b_x - x2)) ? x1 : x2; }
		double getPowerDistY(double b_y) { return (ABS(b_y - y1) < ABS(b_y - y2)) ? y1 : y2; }
};

class Circuit {
	private:
		list<Rod*> rod;
		double n_rod;
		Battery *battery;
		double min_x, min_y, max_x, max_y;
		double best_max_dist_x, best_max_dist_y;
	public:
		Circuit(double _n_rod){
			n_rod = _n_rod;
			min_x = min_y = 1e9;
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
			for (double i=0; i<n_rod; i++){
				double x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;
				rod.push_back(new Rod(x1, y1, x2, y2));
				min_x = MIN(min_x, MIN(x1, x2));
				min_y = MIN(min_y, MIN(y1, y2));
				max_x = MAX(max_x, MAX(x1, x2));
				max_y = MAX(max_y, MAX(y1, y2));
			}
		}
		// Since max(max(x,y)) = max(max(x), max(y)), find minimum power distance x and y separately.
		void calcOptimalPowerDist(double init_x, double init_y){
			double min_rod_x, max_rod_x, min_rod_y, max_rod_y;
			battery->setX(init_x);
			battery->setY(init_y);
			bool converge = false;
			while (!converge) {
				min_rod_x = min_rod_y = 1e9;
				max_rod_x = max_rod_y = 0;
				for (list<Rod*>::iterator it = rod.begin(); it != rod.end(); it++) {
					double rod_x = (*it)->getPowerDistX(battery->getX());
					double rod_y = (*it)->getPowerDistY(battery->getY());

					min_rod_x = MIN(min_rod_x, rod_x);
					max_rod_x = MAX(max_rod_x, rod_x);
					min_rod_y = MIN(min_rod_y, rod_y);
					max_rod_y = MAX(max_rod_y, rod_y);
				}
				double next_x = (min_rod_x + max_rod_x)/2.0;
				double next_y = (min_rod_y + max_rod_y)/2.0;

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

		double solve() {
			calcOptimalPowerDist(min_x, min_y);
			double x1 = best_max_dist_x, y1 = best_max_dist_y;
			calcOptimalPowerDist(max_x, max_y);
			double x2 = best_max_dist_x, y2 = best_max_dist_y;
			double x = MIN(x1, x2), y = MIN(y1, y2);

			return MAX(x, y);
		}
};

int main(int argc, char** argv)
{
	double T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		double n_rod;
		cin >> n_rod;
		Circuit circuit(n_rod);
		cout << "Case #" << test_case+1 << endl;
		circuit.load();
		cout << circuit.solve() << endl;
	}
	return 0;
}
