void memset(void *b, int c, int len)
{
  int i;
  unsigned char *p = b; // Defining pointer b to pointer p
  i = 0; // I(var) as 0
  while(len > 0) // If lenght greater than 0, define *p as c and increase p, subtract length for loop
    {
      *p = c;
      p++;
      len--;
    }
  return(b); // And finally return b
}
