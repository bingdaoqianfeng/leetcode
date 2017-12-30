/*
  Copyright (c) 2009-2017 Dave Gamble and cJSON contributors

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "cJSON.h"

/* Used by some code below as an example datatype. */
struct record
{
    const char *precision;
    double lat;
    double lon;
    const char *address;
    const char *city;
    const char *state;
    const char *zip;
    const char *country;
};


/* Create a bunch of objects as demonstration. */
static int print_preallocated(cJSON *root)
{
    /* declarations */
    char *out = NULL;
    char *buf = NULL;
    char *buf_fail = NULL;
    size_t len = 0;
    size_t len_fail = 0;

    /* formatted print */
    out = cJSON_Print(root);

    /* create buffer to succeed */
    /* the extra 5 bytes are because of inaccuracies when reserving memory */
    len = strlen(out) + 5;
    buf = (char*)malloc(len);
    if (buf == NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    /* create buffer to fail */
    len_fail = strlen(out);
    buf_fail = (char*)malloc(len_fail);
    if (buf_fail == NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    /* Print to buffer */
    if (!cJSON_PrintPreallocated(root, buf, (int)len, 1)) {
        printf("cJSON_PrintPreallocated failed!\n");
        if (strcmp(out, buf) != 0) {
            printf("cJSON_PrintPreallocated not the same as cJSON_Print!\n");
            printf("cJSON_Print result:\n%s\n", out);
            printf("cJSON_PrintPreallocated result:\n%s\n", buf);
        }
        free(out);
        free(buf_fail);
        free(buf);
        return -1;
    }

    /* success */
    printf("%s\n", buf);

    /* force it to fail */
    if (cJSON_PrintPreallocated(root, buf_fail, (int)len_fail, 1)) {
        printf("cJSON_PrintPreallocated failed to show error with insufficient memory!\n");
        printf("cJSON_Print result:\n%s\n", out);
        printf("cJSON_PrintPreallocated result:\n%s\n", buf_fail);
        free(out);
        free(buf_fail);
        free(buf);
        return -1;
    }

    free(out);
    free(buf_fail);
    free(buf);
    return 0;
}

/* Create a bunch of objects as demonstration. */
static void create_objects(void)
{
    /* declare a few. */
    cJSON *root = NULL;
    cJSON *fmt = NULL;
    cJSON *img = NULL;
    cJSON *thm = NULL;
    cJSON *fld = NULL;
    int i = 0;

    /* Our "days of the week" array: */
    const char *strings[7] =
    {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };
    /* Our matrix: */
    int numbers[3][3] =
    {
        {0, -1, 0},
        {1, 0, 0},
        {0 ,0, 1}
    };
    /* Our "gallery" item: */
    int ids[4] = { 116, 943, 234, 38793 };
    /* Our array of "records": */
    struct record fields[2] =
    {
        {
            "zip",
            37.7668,
            -1.223959e+2,
            "",
            "SAN FRANCISCO",
            "CA",
            "94107",
            "US"
        },
        {
            "zip",
            37.371991,
            -1.22026e+2,
            "",
            "SUNNYVALE",
            "CA",
            "94085",
            "US"
        }
    };
    volatile double zero = 0.0;

    /* Here we construct some JSON standards, from the JSON site. */

    /* Our "Video" datatype: */
    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack (\"Bee\") Nimble"));
    cJSON_AddItemToObject(root, "format", fmt = cJSON_CreateObject());
    cJSON_AddStringToObject(fmt, "type", "rect");
    cJSON_AddNumberToObject(fmt, "width", 1920);
    cJSON_AddNumberToObject(fmt, "height", 1080);
    cJSON_AddFalseToObject (fmt, "interlace");
    cJSON_AddNumberToObject(fmt, "frame rate", 24);

    /* Print to text */
    if (print_preallocated(root) != 0) {
        cJSON_Delete(root);
        exit(EXIT_FAILURE);
    }
    cJSON_Delete(root);

    /* Our "days of the week" array: */
    root = cJSON_CreateStringArray(strings, 7);

    if (print_preallocated(root) != 0) {
        cJSON_Delete(root);
        exit(EXIT_FAILURE);
    }
    cJSON_Delete(root);

    /* Our matrix: */
    root = cJSON_CreateArray();
    for (i = 0; i < 3; i++)
    {
        cJSON_AddItemToArray(root, cJSON_CreateIntArray(numbers[i], 3));
    }

    /* cJSON_ReplaceItemInArray(root, 1, cJSON_CreateString("Replacement")); */

    if (print_preallocated(root) != 0) {
        cJSON_Delete(root);
        exit(EXIT_FAILURE);
    }
    cJSON_Delete(root);

    /* Our "gallery" item: */
    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "Image", img = cJSON_CreateObject());
    cJSON_AddNumberToObject(img, "Width", 800);
    cJSON_AddNumberToObject(img, "Height", 600);
    cJSON_AddStringToObject(img, "Title", "View from 15th Floor");
    cJSON_AddItemToObject(img, "Thumbnail", thm = cJSON_CreateObject());
    cJSON_AddStringToObject(thm, "Url", "http:/*www.example.com/image/481989943");
    cJSON_AddNumberToObject(thm, "Height", 125);
    cJSON_AddStringToObject(thm, "Width", "100");
    cJSON_AddItemToObject(img, "IDs", cJSON_CreateIntArray(ids, 4));

    if (print_preallocated(root) != 0) {
        cJSON_Delete(root);
        exit(EXIT_FAILURE);
    }
    cJSON_Delete(root);

    /* Our array of "records": */
    root = cJSON_CreateArray();
    for (i = 0; i < 2; i++)
    {
        cJSON_AddItemToArray(root, fld = cJSON_CreateObject());
        cJSON_AddStringToObject(fld, "precision", fields[i].precision);
        cJSON_AddNumberToObject(fld, "Latitude", fields[i].lat);
        cJSON_AddNumberToObject(fld, "Longitude", fields[i].lon);
        cJSON_AddStringToObject(fld, "Address", fields[i].address);
        cJSON_AddStringToObject(fld, "City", fields[i].city);
        cJSON_AddStringToObject(fld, "State", fields[i].state);
        cJSON_AddStringToObject(fld, "Zip", fields[i].zip);
        cJSON_AddStringToObject(fld, "Country", fields[i].country);
    }

    /* cJSON_ReplaceItemInObject(cJSON_GetArrayItem(root, 1), "City", cJSON_CreateIntArray(ids, 4)); */

    if (print_preallocated(root) != 0) {
        cJSON_Delete(root);
        exit(EXIT_FAILURE);
    }
    cJSON_Delete(root);

    root = cJSON_CreateObject();
    cJSON_AddNumberToObject(root, "number", 1.0 / zero);

    if (print_preallocated(root) != 0) {
        cJSON_Delete(root);
        exit(EXIT_FAILURE);
    }
    cJSON_Delete(root);
}

/*-------------------------------------------------------------------*/
#define MAX_URL_SIZE 4096
#define MAX_METADATA_SIZE 128

typedef struct Representation {
    char url[MAX_URL_SIZE];
    int id;
    char vmimeType[MAX_METADATA_SIZE];
    char vcodecs[MAX_METADATA_SIZE];
    int vwidth;
    int vheight;
    int vframeRate;
    int vbandwidth;
    char amimeType[MAX_METADATA_SIZE];
    char acodecs[MAX_METADATA_SIZE];
    int audioSamplingRate;
    int abandwidth;
    int tbandwidth;
    int startWithSAP;
} Representation;

typedef struct AdaptationSet {
    char url[MAX_URL_SIZE];
    int segmentAlignment;
    int group;
    int vmaxWidth;
    int vmaxHeight;
    int vmaxFrameRate;
    int vmaxBirate;
    char vpar[MAX_METADATA_SIZE];
    int amaxBitrate;
    int segduration;
    struct Representation *representations;
} AdaptationSet;

typedef struct KwaiMultiRateFLVContext {
    char type[MAX_URL_SIZE];
    char mediaPresentationDuration[MAX_METADATA_SIZE];
    struct AdaptationSet *adaptationSets[3];
    int n_adaptationSet;
} KwaiMultiRateFLVContext;

static int parse_json_node( cJSON * json, int * align_count )
{
    switch(json->type)
    {
    case cJSON_False:
        printf("%s : false",json->string);
        break;
    case cJSON_True:
        printf("%s : true",json->string);
        break;
    case cJSON_NULL:
        printf("null");
        break;
    case cJSON_Number:
        printf("[cJSON_Number] %s : %ll",json->string,json->valuedouble);
        break;
    case cJSON_String:
        printf("[cJSON_String] %s : \"%s\"",json->string,json->valuestring);
        break;
    case cJSON_Array:
        {
            if(json->string)
            {
                printf("[cJSON_Array] %s : ",json->string);
            }
            ++*align_count;
            printf("[\n");
 
 
            int len = cJSON_GetArraySize(json);
            for(int i = 0;i<len;i++)
            {
                cJSON * child_json = cJSON_GetArrayItem(json,i);
                parse_json_node( child_json , align_count);
                printf("\n");
            }
            --*align_count;
            for(int i = 0;i<*align_count;i++)
            {
                printf("  ");
            }
            printf("]");
 
        }
        break;
    case cJSON_Object:
        {
            if(json->string)
            {
                printf("[cJSON_Object] %s : ",json->string);
            }
            ++*align_count;
            printf("{\n");
            int len = cJSON_GetArraySize(json);
            for(int i = 0;i<len;i++)
            {
                cJSON * child_json = cJSON_GetArrayItem(json,i);
                parse_json_node( child_json , align_count);
                printf("\n");
            }
            --*align_count;
            for(int i = 0;i<*align_count;i++)
            {
                printf("  ");
            }
             printf("}");
        }
        break;
    }

    printf("\n");

    return 0;
}

/****************************************************************/

static int parser_representation_set( AdaptationSet *c, cJSON * root)
{

}




static int parser_adaptation_set( AdaptationSet *c, cJSON * root)
{
    int len = cJSON_GetArraySize(root);
    for(int i = 0;i<len;i++){
        cJSON * child_json = cJSON_GetArrayItem(root,i);

        switch(child_json->type){
            case cJSON_False:
                if(!strcmp(child_json->string, "segmentAlignment")){
                    c->segmentAlignment = 0;
                    printf("segmentAlignment: %d \n",c->segmentAlignment);
                }
                break;
            case cJSON_True:
                if(!strcmp(child_json->string, "segmentAlignment")){
                    c->segmentAlignment = 1;
                    printf("segmentAlignment: %d \n",c->segmentAlignment);
                }
                break;
            case cJSON_Number:
                if(!strcmp(child_json->string, "group")){
                    c->group = (int)root->valuedouble;
                    printf("group: %d \n",c->group);
                }else if(!strcmp(child_json->string, "vmaxWidth")){
                    c->vmaxWidth = (int)root->valuedouble;
                    printf("vmaxWidth: %d \n",c->vmaxWidth);
                }else if(!strcmp(child_json->string, "vmaxHeight")){
                    c->vmaxHeight= (int)root->valuedouble;
                    printf("vmaxHeight: %d \n",c->vmaxHeight);
                }else if(!strcmp(child_json->string, "vmaxFrameRate")){
                    c->vmaxFrameRate= (int)root->valuedouble;
                    printf("vmaxFrameRate: %d \n",c->vmaxFrameRate);
                }else if(!strcmp(child_json->string, "vmaxBirate")){
                    c->vmaxBirate= (int)root->valuedouble;
                    printf("vmaxBirate: %d \n",c->vmaxBirate);
                }else if(!strcmp(child_json->string, "amaxBitrate")){
                    c->amaxBitrate= (int)root->valuedouble;
                    printf("amaxBitrate: %d \n",c->amaxBitrate);
                }else if(!strcmp(child_json->string, "segduration")){
                    c->segduration= (int)root->valuedouble;
                    printf("segduration: %d \n",c->segduration);
                }
                break;
            case cJSON_String:
                if(!strcmp(child_json->string, "urltemplate")){
                    strcpy(c->url, child_json->valuestring);
                    printf("url: \"%s\" \n",c->url);
                }else if(!strcmp(child_json->string, "vpar")){
                    strcpy(c->vpar, child_json->valuestring);
                    printf("vpar: \"%s\" \n",c->vpar);
                }
                break;
            
            case cJSON_Array:
                if(child_json->string && !strcmp(child_json->string, "Representation")) {
                    printf("[cJSON_Array] %s \n",child_json->string);
                    
                }
                break;
            case cJSON_NULL:
                printf("jason error \n");
                break;
            case cJSON_Object:
                printf("jason should not include this \n");
                break;
        }
    }
}


static int parser_root(char *file_name, KwaiMultiRateFLVContext *c)
{
    /* declarations */
    int align_count;
    cJSON *root = cJSON_Parse(file_name);

    if(cJSON_Object == root->type){
        int len = cJSON_GetArraySize(root);
        for(int i = 0;i<len;i++){
            cJSON * child_json = cJSON_GetArrayItem(root,i);

            switch(child_json->type){
                case cJSON_String:
                    if(!strcmp(child_json->string, "type")){
                        strcpy(c->type, child_json->valuestring);
                        printf("type: \"%s\" \n",c->type);
                    }else if(!strcmp(child_json->string, "mediaPresentationDuration")){
                        strcpy(c->mediaPresentationDuration, child_json->valuestring);
                        printf("mediaPresentationDuration: \"%s\" \n",c->mediaPresentationDuration);
                    }
                    break;
                case cJSON_Object:
                    if(child_json->string && !strcmp(child_json->string, "AdaptationSet")) {
                        printf("[cJSON_Object] %s \n",child_json->string);
                        AdaptationSet *adaptationSetItem = NULL;
                        adaptationSetItem = malloc(sizeof(AdaptationSet));
                        if(!adaptationSetItem){
                            //manifest_free(c);
                            return -1;
                        }
                        c->adaptationSets[c->n_adaptationSet] = adaptationSetItem;
                        c->n_adaptationSet++;
                        parser_adaptation_set(adaptationSetItem, child_json);
                    }
                    break;

                case cJSON_NULL:
                    printf("jason error \n");
                    break;
                case cJSON_False:
                case cJSON_True:
                case cJSON_Number:
                case cJSON_Array:
                    printf("jason root should not include this \n");
                    break;
            }
            printf("\n");
        }

    }
    
    cJSON_Delete(root);
}

static void init_multi_rate_flv_context(KwaiMultiRateFLVContext *c)
{
    if(!c)
        return;
    c->n_adaptationSet = 0;
}

#if 0
static void manifest_free(KwaiMultiRateFLVContext *c){
    return;
}
#endif

static int parser_manifest(void)
{
    //char* filename = "/Users/liuyuxin/sourcecode/github/manifext.json";
    //char* filename = "/Users/liuyuxin/sourcecode/github/json-parser/tests/valid-0000.json";
    char* filename = "/Users/liuyuxin/sourcecode/github/manifext_new.json";
    FILE *fp;
    struct stat filestatus;
    int file_size;
    char* file_contents;

    if ( stat(filename, &filestatus) != 0) {
        printf("File %s not found\n", filename);
        return 1;
    }
    file_size = filestatus.st_size;
    file_contents = (char*)malloc(filestatus.st_size);
    if ( file_contents == NULL) {
        printf("Memory error: unable to allocate %d bytes\n", file_size);
        return 1;
    }

    fp = fopen(filename, "rt");
    if (fp == NULL) {
        printf("Unable to open %s\n", filename);
        fclose(fp);
        free(file_contents);
        return 1;
    }
    if ( fread(file_contents, file_size, 1, fp) != 1 ) {
        printf("Unable t read content of %s\n", filename);
        fclose(fp);
        free(file_contents);
        return 1;
    }
    fclose(fp);

    printf("%s\n", file_contents);

    printf("--------------------------------\n\n");
    KwaiMultiRateFLVContext c;

    init_multi_rate_flv_context(&c);
    parser_root(file_contents, &c);
}


int main(void)
{
    /* print the version */
    printf("Version: %s\n", cJSON_Version());

    /* Now some samplecode for building objects concisely: */
    //create_objects();

    parser_manifest();

    return 0;
}
