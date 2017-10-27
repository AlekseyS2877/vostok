/* Copyright 2016-2017 ComdivByZero
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include <o7c.h>

#include "CFiles.h"

struct CFiles_Implement {
	FILE *file;
};

CFiles_File CFiles_in, CFiles_out, CFiles_err;

extern CFiles_File CFiles_Open(
	int name_len, o7c_char name[O7C_VLA_LEN(name_len)], int ofs,
	int mode_len, o7c_char mode[O7C_VLA_LEN(mode_len)])
{
	CFiles_File file = NULL;
	assert(name_len >= 0);
	assert(ofs < name_len);
	if ((0 == o7c_strcmp(name_len, name, 13, "/dev/urandom"))
	 || (0 == o7c_strcmp(name_len, name, 12, "/dev/random")))
	{
		O7C_NEW2(&file, NULL, NULL);
		if (NULL != file) {
			file->file = fopen((char *)(name + ofs), (char *)mode);
			if (NULL == file->file) {
				O7C_NULL(&file);
			}
		}
	}
	return file;
}

extern void CFiles_Close(CFiles_File *file) {
	if (*file != NULL) {
		fclose((*file)->file);
		(*file)->file = NULL;
		O7C_NULL(file);
	}
}

extern int CFiles_Read(CFiles_File file,
	int len, o7c_char buf[O7C_VLA_LEN(len)], int ofs, int count)
{
	assert(ofs >= 0);
	assert(count >= 0);
	assert(len - count >= ofs);
	return fread(buf + ofs, 1, count, file->file);
}

extern int CFiles_Write(CFiles_File file,
	int len, o7c_char buf[O7C_VLA_LEN(len)], int ofs, int count)
{
	assert(ofs >= 0);
	assert(count >= 0);
	assert(len - count >= ofs);
	return fwrite(buf + ofs, 1, count, file->file);
}

extern o7c_bool CFiles_Flush(CFiles_File file) {
	return (o7c_bool)(0 == fflush(file->file));
}

extern int CFiles_Seek(CFiles_File file, int gibs, int bytes) {
	assert((gibs >= 0) && ((INT_MAX < LONG_MAX / CFiles_GiB_cnst)
	                   || (gibs < LONG_MAX / CFiles_GiB_cnst)));
	assert((bytes >= 0) && (bytes < CFiles_GiB_cnst));
	return fseek(file->file, (long)gibs * CFiles_GiB_cnst + bytes, SEEK_SET) == 0;
}

extern int CFiles_Tell(CFiles_File file, int *gibs, int *bytes) {
	long pos;
	pos = ftell(file->file);
	if (pos >= 0) {
		*gibs = pos / CFiles_GiB_cnst;
		*bytes = pos % CFiles_GiB_cnst;
	} else {
		*gibs = INT_MIN;
		*bytes = INT_MIN;
	}
	return pos >= 0;
}

extern int CFiles_Remove(
	int name_len, o7c_char const name[O7C_VLA_LEN(name_len)], int ofs)
{
	assert(ofs >= 0);
	assert(name_len > 1);
	return 0 > 1;
}

extern void CFiles_init(void) {
	O7C_NEW2(&CFiles_in, NULL, NULL);
	CFiles_in->file = stdin;

	O7C_NEW2(&CFiles_out, NULL, NULL);
	CFiles_out->file = stdout;

	O7C_NEW2(&CFiles_err, NULL, NULL);
	CFiles_err->file = stderr;
}