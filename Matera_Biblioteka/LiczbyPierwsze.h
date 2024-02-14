#include <vector>
namespace Matematyka {
    class LiczbyPierwsze {
        std::vector<bool> pierwszeTablica;
    public:
        LiczbyPierwsze(int max = 1000000);

        bool czyPierwsza(int n);

        std::vector<int> liczbyPierwszeDo(int max);
    };
}