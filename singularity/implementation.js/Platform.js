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

var platform;

var module = {};
o7.export.Platform = module;

if (typeof require !== 'undefined') {
    platform = require("os").platform();
}

module.Posix      = platform == 'linux' || platform == 'darwin'
                 || platform == 'openbsd' || platform == 'freebsd'
                 || platform == 'sunos';
module.Linux      = platform == 'linux';
module.Bsd        = platform == 'freebsd';
module.Dos        = false;
module.Windows    = platform == 'win32';
module.Darwin     = platform == 'darwin';

module.C          = false;
module.Java       = false;
module.Javascript = true;

return module;
})(o7 || (o7 = {}));

