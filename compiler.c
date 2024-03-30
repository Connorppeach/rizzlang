#include <stdio.h>
#define MSOF "#include <stdio.h>\n#include <stdlib.h>\n#include <time.h>\n\nunsigned long int mem[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};\n\nint main() {\n   srand(time(NULL));\n"
#define EEOF "\n}"


int cpytoquote(char *s1, char *s2) {
  int e = 0;
  while(*s1 != '\0') {
    *s2 = *s1;
    s1++;
    s2++;
    e++;
    if(*s1 == '"')
      break;
  }
  *s2='"';
  s2++;
  *s2 = '\0';
  return e;
}

int cpytospace(char *s1, char *s2) {
  int e = 0;
  while(*s1 != ' ' && *s1 != '\0') {
    *s2 = *s1;
    s1++;
    s2++;
    e++;
  }

  *s2 = '\0';
  return e;
}
int readint(char *s1, int *dec) {
  int e = 0;
  *dec = 0;
  while(*s1 - '0' > -1 && *s1 - '0' < 10) {
    *dec *= 10; 
    *dec += (*s1++ - '0');
    e++;
  }
  return e;
}

char mcmpstr(char *s1, char *s2) {
  char *t1=s1, *t2=s2;
  while(*t1 != '\0' && *t2 != '\0') {
    if(*t1++ != *t2++)
      return 0;
  };
  return 1;
}
void parse (char *pos) {
  char tmpstr[512];
  int dec = 0;
  pos+=cpytospace(pos, tmpstr);
  if(mcmpstr(tmpstr, "yap") == 1) {
      while((*pos++) == ' ');
      pos+=cpytoquote(--pos, tmpstr);
      if(*tmpstr=='"')
	printf("    puts(%s);\n", tmpstr);
      else
	printf("    printf(\"%%d\\n\", mem[%d]);\n", *tmpstr-'A');
	
    } else if(mcmpstr(tmpstr, "outta_pocket") == 1) {
      while((*pos++) == ' ');
      pos+=cpytoquote(--pos, tmpstr);
      printf("    mem[%d] = rand();\n", *tmpstr-'A');
    } else if(mcmpstr(tmpstr, "cook") == 1) {
      while((*pos++) == ' ');
      pos+=readint(--pos, &dec);
      printf("    goto m%d;\n", dec);
  } else if(mcmpstr(tmpstr, "iykyk") == 1) {
      while((*pos++) == ' ');
      pos+=cpytoquote(--pos, tmpstr);
      printf("    scanf(\"%%d\", &mem[%d]);\n", *tmpstr-'A');
    } else if(mcmpstr(tmpstr, "find_out") == 1) {
      while((*pos++) == ' ');
      pos+=cpytospace(--pos, tmpstr);
      char tmp = *tmpstr-'A';
      printf("    for(mem[%d] = ", *tmpstr-'A');
      while(++(*pos) == ' ');
      pos++;
      while(++(*pos) == ' ');
      pos++;
      while(++(*pos) == ' ');
      pos++;
      pos+=readint(pos, &dec);
      printf("%d; mem[%d] <= ", dec, tmp);
      pos++;
      while((*pos++) == ' ');
      pos--;
      pos+=cpytospace(pos, tmpstr);
      
      if(mcmpstr(tmpstr, "run_wit_it") == 1) {
	while((*pos++) == ' ');
	pos--;
	pos+=readint(pos, &dec);
	printf("%d; mem[%d]++) {\n", dec, tmp);
      }
    } else if(mcmpstr(tmpstr, "swipe_left") == 1) {
      printf("    };\n");
    } else if(mcmpstr(tmpstr, "kms") == 1) {
      printf("    return 0;\n");
    }  else if(mcmpstr(tmpstr, "vibe_check") == 1) {
      while((*pos++) == ' ');
      pos+=cpytospace(--pos, tmpstr);
      char tmp1,tmp2; 
     
      if(*tmpstr <= 'Z'  &&*tmpstr >= 'A')
	tmp1 = *tmpstr-'A';
      printf("    if(mem[%d]", tmp1);
      while((*pos++) == ' ');
      pos--;
      if(*pos == '=')
	printf("==");
      else
	printf("%c", *pos);
      pos++;
      while((*pos++) == ' ');
      pos--;
      if(*pos <= 'Z'  &&*pos >= 'A')
	tmp2 = *pos-'A';
      
      printf("mem[%d]) \n", tmp2);
      pos++;
      while((*pos++) == ' ');
      pos--;
      pos+=cpytospace(pos, tmpstr);
      pos++;
      while((*pos++) == ' ');
      pos--;
      if(mcmpstr(tmpstr, "finna") == 1) {
	parse(pos);

	

      }
  } else {
    pos--;
    while((*pos++) == ' ');
    pos--;
    printf("mem[%d] = ", *pos-'A');
    pos++;
    while((*pos++) == ' ');
    pos--;
    if(*pos == '=') {
      pos++;
      while((*pos++) == ' ');
      pos--;
      if(*pos <= 'Z'  &&*pos >= 'A')
	printf("mem[%d]", *pos-'A');
      else {
	pos+=cpytospace(pos, tmpstr);
	printf("%s", tmpstr);
      }
      pos++;
      while((*pos++) == ' ');
      pos--;
      pos+=cpytospace(pos, tmpstr);
      printf("%s", tmpstr);
      pos++;
      while((*pos++) == ' ');
      pos--;
      if(*pos <= 'Z'  &&*pos >= 'A')
	printf("mem[%d];", *pos-'A');
      else {
	pos+=cpytospace(pos, tmpstr);
	printf("%s;\n", tmpstr);
      }
      pos++;
      while((*pos++) == ' ');
      pos--;
    }
  }

}
int main () {
  char line[1024];
  
  puts(MSOF);
  while (fgets(line, 1024, stdin) != NULL) {
    int i = -1;
    while(line[++i] == ' ');
    int dec = 0;
    while(line[i] - '0' > -1 && line[i] - '0' < 10) {
      dec *= 10; 
      dec += (line[i++] - '0');
    }
    if(dec != 0)
      printf("m%d:\n", dec);
    while(line[++i] == ' ');
    
    char *pos = &line[i];
    parse(pos);

  }
  puts(EEOF);
}
