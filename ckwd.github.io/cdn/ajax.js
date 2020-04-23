!function(){
    const ajax = function (url, settings) {
        ({ method = 'GET', responseType = '', header = {}, timeout = 0, data = null, async = true } = settings || {});
        
        let getXhr = () => new XMLHttpRequest() || new ActiveXObject("Microsoft.XMLHTTP");

        class DataFormater {
            constructor(data) {
                this._data = data;
            }

            getJson() {
                let __data = typeof this._data === 'object'
                ? this._data
                : JSON.parse(this._data);


                return __data === null
                    ? __data
                    : (__data.d && __data.d !== '' ? JSON.parse(__data.d) : __data); 
            }

            getText() {
                return this._data;
            }
        }

        return new Promise((resolve, reject) => {
            const xhr = getXhr();

            xhr.open(method, url, async);

            xhr.onreadystatechange = function () {
                if (this.readyState !== 4) return;

                this.status === 200
                    ? resolve(new DataFormater(this.response))
                    : reject(new Error(this.statusText));
            }

            xhr.timeout = timeout;
            xhr.responseType = responseType;

            for (let item in header) {
                xhr.setRequestHeader(item, `application/${header[item]}`);
            }

            xhr.send(data);
        });
    };

    window.ajax = window.ajax || ajax;
}();
// console.log('ok');
