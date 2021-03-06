/* Copyright 2019 ComdivByZero
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
var o7;
(function(o7) { 'use strict';

var module = {};
o7.export.JsRand = module;

var crypto;

function Open() {
	var ok;
	if (crypto) {
		ok = true;
	} else {
		ok = typeof require !== 'undefined';
		if (ok) {
			crypto = require("crypto");
			ok = typeof crypto !== 'undefined';
		}
	}
	return ok;
}
module.Open = Open;

function Close() {
	crypto = undefined;
}
module.Close = Close;

function Read(buf, ofs, count) {
	var data, i;

	o7.assert(0 < count);
	o7.assert((0 <= ofs) && (ofs <= buf.length - count));
	if (buf instanceof Uint8Array) {
		crypto.randomFillSync(buf, ofs, count);
	} else {
		data = new Uint8Array(count);
		crypto.randomFillSync(data);
		for (i = 0; i < count; i += 1) {
			buf[ofs + i] = data[i];
		}
	}
	return true;
}
module.Read = Read;

return module;
})(o7 || (o7 = {}));
