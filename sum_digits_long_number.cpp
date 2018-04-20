int digit_sum(long long number) {

  //long type has a width of 32 bits 2,147,483,647
  //long long has a width of 64 bits 9,223,372,036,854,775,807

    int sumDigits = 0;
    int digit = 0;

    if (number<0)
        number=number*-1;

    while(number>0){
        digit=number%10;
        number=number/10;
        sumDigits=sumDigits+digit;
    }

    return sumDigits;

}
