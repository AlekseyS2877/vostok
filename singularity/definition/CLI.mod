(* Copyright 2016, 2018 ComdivByZero
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
MODULE CLI;

CONST MaxLen* = 4096;

VAR count*: INTEGER;

PROCEDURE GetName*(VAR str: ARRAY OF CHAR; VAR ofs: INTEGER): BOOLEAN;
BEGIN
	ASSERT((0 <= ofs) & (ofs < LEN(str)));
	RETURN FALSE
END GetName;

PROCEDURE Get*(VAR str: ARRAY OF CHAR; VAR ofs: INTEGER; arg: INTEGER): BOOLEAN;
BEGIN
	ASSERT((0 <= ofs) & (ofs < LEN(str)));
	ASSERT((0 <= arg) & (arg < count));
	RETURN FALSE
END Get;

PROCEDURE SetExitCode*(code: INTEGER);
END SetExitCode;

BEGIN
	count := 0
END CLI.
