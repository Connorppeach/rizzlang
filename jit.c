#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tinycc/libtcc.h"


#define MSOF "#include <stdio.h>\n#include <stdlib.h>\n#include <time.h>\n\nunsigned long int mem[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};\n\nint main() {\n   srand(time(NULL));\n"
#define EEOF "\n}"
int msz = 0;
char *mstr;
char *mstr2;

void addtostr(char *new) {
  
  msz = msz+strlen(new);
  mstr = (char*)realloc(mstr, msz * (sizeof(char)+1));
  
  strcat(mstr, new);
}

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
void skipspaces(char **p) {
  while((*((*p)++)) == ' ');
  (*p)--;  
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
  char tmpstr2[512];
  int dec = 0;
  pos+=cpytospace(pos, tmpstr);
  if(mcmpstr(tmpstr, "yap") == 1) {
    skipspaces(&pos);
    pos+=cpytoquote(pos, tmpstr);
    if(*tmpstr=='"') {
      sprintf(tmpstr2, "    printf(\"%%s\\n\", %s);\n", tmpstr);
      addtostr(tmpstr2);
    } else {
      sprintf(tmpstr2, "    printf(\"%%d\\n\", mem[%d]);\n", *tmpstr-'A');
      addtostr(tmpstr2);
    }
  } else if(mcmpstr(tmpstr, "outta_pocket") == 1) {
    skipspaces(&pos);
    pos+=cpytospace(pos, tmpstr);
    sprintf(tmpstr2, "    mem[%d] = rand();\n", *tmpstr-'A');
    addtostr(tmpstr2);
  } else if(mcmpstr(tmpstr, "rizz_up") == 1) {
    skipspaces(&pos);
    sprintf(tmpstr2, "    mem[%d] = ", *pos-'A');
    addtostr(tmpstr2);
    pos++;
    skipspaces(&pos);
    sprintf(tmpstr2, "mem[%d];\n", *pos-'A');
    addtostr(tmpstr2);
  } else if(mcmpstr(tmpstr, "cook") == 1) {
    skipspaces(&pos);
    pos+=readint(pos, &dec);
    sprintf(tmpstr2, "    goto m%d;\n", dec);
    addtostr(tmpstr2);
  } else if(mcmpstr(tmpstr, "iykyk") == 1) {
    skipspaces(&pos);
    pos+=cpytospace(pos, tmpstr);
    sprintf(tmpstr2, "    scanf(\"%%d\", &mem[%d]);\n", *tmpstr-'A');
    addtostr(tmpstr2);
  } else if(mcmpstr(tmpstr, "find_out") == 1) {
    skipspaces(&pos);
    pos+=cpytospace(pos, tmpstr);
    char tmp = *tmpstr-'A';
    sprintf(tmpstr2, "    for(mem[%d] = ", *tmpstr-'A');
    addtostr(tmpstr2);
    while(++(*pos) == ' ');
    pos++;
    while(++(*pos) == ' ');
    pos++;
    while(++(*pos) == ' ');
    pos++;
    pos+=readint(pos, &dec);
    sprintf(tmpstr2, "%d; mem[%d] <= ", dec, tmp);
    addtostr(tmpstr2);
    pos++;
    skipspaces(&pos);
    pos+=cpytospace(pos, tmpstr);
      
    if(mcmpstr(tmpstr, "run_wit_it") == 1) {
      skipspaces(&pos);
      pos+=readint(pos, &dec);
      sprintf(tmpstr2, "%d; mem[%d]++) {\n", dec, tmp);
      addtostr(tmpstr2);
    }
  } else if(mcmpstr(tmpstr, "swipe_left") == 1) {
    sprintf(tmpstr2, "    };\n");
    addtostr(tmpstr2);
  } else if(mcmpstr(tmpstr, "kms") == 1) {
    sprintf(tmpstr2, "    return 0;\n");
    addtostr(tmpstr2);
  }  else if(mcmpstr(tmpstr, "vibe_check") == 1) {
    while((*pos++) == ' ');
    pos+=cpytospace(--pos, tmpstr);
    char tmp1,tmp2; 
     
    if(*tmpstr <= 'Z'  &&*tmpstr >= 'A')
      tmp1 = *tmpstr-'A';
    sprintf(tmpstr2, "    if(mem[%d]", tmp1);
    addtostr(tmpstr2);
    skipspaces(&pos);
    if(*pos == '=') {
      sprintf(tmpstr2, "==");
      addtostr(tmpstr2);
    } else {
      sprintf(tmpstr2, "%c", *pos);
      addtostr(tmpstr2);

    }
    pos++;
    skipspaces(&pos);
    if(*pos <= 'Z'  &&*pos >= 'A')
      tmp2 = *pos-'A';
      
    sprintf(tmpstr2, "mem[%d]) \n", tmp2);
    addtostr(tmpstr2);
    pos++;
    skipspaces(&pos);
    pos+=cpytospace(pos, tmpstr);
    pos++;
    skipspaces(&pos);
    if(mcmpstr(tmpstr, "finna") == 1) {
      parse(pos);

	

    }
  } else {
    pos--;
    skipspaces(&pos);
    sprintf(tmpstr2, "mem[%d] = ", *pos-'A');
    addtostr(tmpstr2);
    pos++;
    skipspaces(&pos);
    if(*pos == '=') {
      pos++;
      skipspaces(&pos);
      if(*pos <= 'Z'  &&*pos >= 'A') {
	sprintf(tmpstr2, "mem[%d]", *pos-'A');
	addtostr(tmpstr2);
      }
      else {
	pos+=cpytospace(pos, tmpstr);
	sprintf(tmpstr2, "%s", tmpstr);
	addtostr(tmpstr2);
      }
      pos++;
      skipspaces(&pos);
      pos+=cpytospace(pos, tmpstr);
      sprintf(tmpstr2, "%s", tmpstr);
      addtostr(tmpstr2);
      pos++;
      skipspaces(&pos);
      if(*pos <= 'Z'  &&*pos >= 'A') {
	sprintf(tmpstr2, "mem[%d];", *pos-'A');
	addtostr(tmpstr2);
      } else {
	pos+=cpytospace(pos, tmpstr);
	sprintf(tmpstr2, "%s;\n", tmpstr);
	addtostr(tmpstr2);
      }
      pos++;
      skipspaces(&pos);
    }
  }

}
int main (int argc, char **argv) {
  char *line = NULL;
  char tmpstr[512];
  mstr = (char*)malloc(sizeof(char));
  mstr[0] = '\0';
  FILE * fp;
  size_t len = 0;
  fp = fopen(argv[1], "r");
  addtostr(MSOF);
  while ((getline(&line, &len, fp)) != -1) {
    int i = -1;
    while(line[++i] == ' ');
    int dec = 0;
    while(line[i] - '0' > -1 && line[i] - '0' < 10) {
      dec *= 10; 
      dec += (line[i++] - '0');
    }
    if(dec != 0) {
      sprintf(tmpstr, "m%d:\n", dec);
      addtostr(tmpstr);
    }
    while(line[++i] == ' ');
    
    char *pos = &line[i];
    parse(pos);

  }
  addtostr(EEOF);
  
  void *mem;
  TCCState *s = tcc_new();
  tcc_set_lib_path(s, ".");
  tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
  tcc_set_options(s, "g");
  tcc_add_include_path(s, "/usr/lib/tcc/include");
  tcc_compile_string(s, mstr);
  int size = tcc_relocate(s);
  if (size == -1)
    return 1;  addtostr(EEOF);
  
  int (*func)(int argc, char **argv) = tcc_get_symbol(s, "main");
  if (!func)
    return 1;
  func(0, NULL);
  tcc_delete(s);
}
