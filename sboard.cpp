//#include "sboard.h"
#include <iostream>
using namespace std;

#define INT_MIN -2147483648

SBoard::SBoard(int num_competitors, int num_periods)
{
  m_num_competitors= num_competitors;
  m_num_periods = num_periods;
  m_scores= new int*[num_periods];
  for(int i = 0; i < num_periods; ++i)
  {
    *(m_scores+i) = new int[num_competitors];
  }
}
SBoard::~SBoard()
{
  for(int i = 0; i < m_num_periods; ++i)
  {
    delete *(m_scores+i);
  }
  delete m_scores;
}

void SBoard::setScore(int competitor, int period, int score)
{
  if(InBound(competitor, period))
  {
    m_scores[competitor-1][period-1] = score;
  }
  else
  {
    cout << "out of bounds" << endl;
  }
}



int SBoard::getScore(int competitor, int period)
{
  if(InBound(competitor, period))
  {
    return m_scores[competitor-1][period-1];
  }
  else
  {
    cout << "out of bounds" << endl;
    return INT_MIN;
  }
}


 int SBoard::getTotalScore(int competitor)
{
  int total=0;
  if(InBound(competitor, 0))
  {
    for(int i=0; i< m_num_periods; i++)
    {
      total =+ m_scores[competitor-1][i];
    }
    return total;
  }
  else
  {
    cout << "out of bounds" << endl;
  }
}

void SBoard::clearScoreboard()
{
  for(int i=0; i<m_num_competitors; i++)
  {
    for(int y=0; y<m_num_periods; y++)
    {
      m_scores[i][y] =0;
    }
  }
}

bool SBoard::InBound(int competitor, int period)
{
  if(competitor <= m_num_competitors && competitor >= 0 && period <= m_num_periods && period >=0)
  {
    return true;
  }
  return false;
}
