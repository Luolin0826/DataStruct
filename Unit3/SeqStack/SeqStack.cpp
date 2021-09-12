void inc_ldkz()
{
  if (K4 == 0) //有人在
  {
    counter2 = 0;
    counter1++;
    if (counter1 < 3)
    {
      bl1 = 1;
    }
    else
    {
      bl1 = counter1 - 2;
      if (bl1 > 5)
      {
        bl1 = 5;
      }
    }
    switch (bl1)
    {
    case 1:
      P2 = 0x0f;
      break;
    case 2:
      P2 = 0x07;
      break;
    case 3:
      P2 = 0x03;
      break;
    case 4:
      P2 = 0x01;
      break;
    case 5:
      P2 = 0x00;
      break;
    }
  }
  else
  {
    counter1 = 0;
    counter2++;
    if (counter2 > 5)
    {
      bl2 = counter2 - 5;
      if (bl2 > 5)
      {
        bl2 = 5;
      }

      switch (bl2)
      {
      case 1:
        P2 |= 0x01;
        break;
      case 2:
        P2 |= 0x02;
        break;
      case 3:
        P2 |= 0x04;
        break;
      case 4:
        P2 |= 0x08;
        ;
        break;
      case 5:
        P2 |= 0x10;
        ;
        break;
      }
    }
  }
}
