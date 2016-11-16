#include "IScoreboard.h"

class Scoreboard: public IScoreboard
{
public:
  Scoreboard(int num_competitors, int num_periods);
  ~Scoreboard();
  int getScore(int competitor, int period);
  void setScore(int competitor, int period, int score);
  int getTotalScore(int competitor);
  void clearScoreboard();
  bool InBound(int competitor, int period);

protected:
  int m_num_competitors;
  int m_num_periods;
  int **m_scores;
  bool InBounds(int competitor, int period);
};

