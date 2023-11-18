int largest(const int list[], int lowerIndex, int upperIndex)
{
  if (lowerIndex == upperIndex)
  {
    return list[lowerIndex];
  }
  else
  {
    int max = largest(list, lowerIndex + 1, upperIndex);
    if (list[lowerIndex] > max)
    {
      return list[lowerIndex];
    }
    else
    {
      return max;
    }
  }
}