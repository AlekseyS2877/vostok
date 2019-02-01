(* Copyright 2019 ComdivByZero
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
 *)
MODULE ArrayCopy;

  PROCEDURE Chars*(VAR dest: ARRAY OF CHAR; destOfs: INTEGER;
                        src: ARRAY OF CHAR;  srcOfs: INTEGER;
                   count: INTEGER);
  VAR di, si, last: INTEGER;
  BEGIN
    ASSERT(count > 0);
    ASSERT((0 <= destOfs) & (destOfs <= LEN(dest) - count));
    ASSERT((0 <= srcOfs) & (srcOfs <= LEN(src) - count));

    last := destOfs + count - 1;
    IF destOfs = srcOfs THEN
      FOR di := destOfs TO last DO
        dest[di] := src[di]
      END
    ELSE
      si := srcOfs;
      FOR di := destOfs TO last DO
        dest[di] := src[si];
        INC(si)
      END
    END
  END Chars;

  PROCEDURE Bytes*(VAR dest: ARRAY OF BYTE; destOfs: INTEGER;
                        src: ARRAY OF BYTE;  srcOfs: INTEGER;
                   count: INTEGER);
  VAR di, si, last: INTEGER;
  BEGIN
    ASSERT(count > 0);
    ASSERT((0 <= destOfs) & (destOfs <= LEN(dest) - count));
    ASSERT((0 <= srcOfs) & (srcOfs <= LEN(src) - count));

    last := destOfs + count - 1;
    IF destOfs = srcOfs THEN
      FOR di := destOfs TO last DO
        dest[di] := src[di]
      END
    ELSE
      si := srcOfs;
      FOR di := destOfs TO last DO
        dest[di] := src[si];
        INC(si)
      END
    END
  END Bytes;

  PROCEDURE CharsToBytes*(VAR dest: ARRAY OF BYTE; destOfs: INTEGER;
                               src: ARRAY OF CHAR;  srcOfs: INTEGER;
                          count: INTEGER);
  VAR di, si, last: INTEGER;
  BEGIN
    ASSERT(count > 0);
    ASSERT((0 <= destOfs) & (destOfs <= LEN(dest) - count));
    ASSERT((0 <= srcOfs) & (srcOfs <= LEN(src) - count));

    last := destOfs + count - 1;
    IF destOfs = srcOfs THEN
      FOR di := destOfs TO last DO
        dest[di] := ORD(src[di])
      END
    ELSE
      si := srcOfs;
      FOR di := destOfs TO last DO
        dest[di] := ORD(src[si]);
        INC(si)
      END
    END
  END CharsToBytes;

  PROCEDURE BytesToChars*(VAR dest: ARRAY OF CHAR; destOfs: INTEGER;
                               src: ARRAY OF BYTE;  srcOfs: INTEGER;
                          count: INTEGER);
  VAR di, si, last: INTEGER;
  BEGIN
    ASSERT(count > 0);
    ASSERT((0 <= destOfs) & (destOfs <= LEN(dest) - count));
    ASSERT((0 <= srcOfs) & (srcOfs <= LEN(src) - count));

    last := destOfs + count - 1;
    IF destOfs = srcOfs THEN
      FOR di := destOfs TO last DO
        dest[di] := CHR(src[di])
      END
    ELSE
      si := srcOfs;
      FOR di := destOfs TO last DO
        dest[di] := CHR(src[si]);
        INC(si)
      END
    END
  END BytesToChars;

END ArrayCopy.
