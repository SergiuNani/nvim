// fold if ==13 and the else if part musnt be folded 
function createObjectAndAppend(arr) {
    if (arr.length == 13) {
        //Create a new object
        var obj = {};
        var ArrayOfObjects = [];
        var textArr = [];

        obj["PID"] = arr[0].querySelector("span").innerText;
        obj["Description"] = arr[1].querySelector("span").innerText;

        arr = arr.slice(3).slice(0, -1);
        // console.log(arr)
        arr.forEach((el, index) => {
            textArr[index] = el.querySelector("span").innerText;
            if (index == 3) {
                textArr[index] = el.querySelector("input").checked.toString();
            }
        });
        ArrayOfObjects.push(textArr);

        obj["Data"] = ArrayOfObjects;

        TempTable.push(obj);
    } else if (arr.length == 10) {
        //take the last object and add to it

        var textArr = [];
        arr = arr.slice(0, -1);

        arr.forEach((el, index) => {
            textArr[index] = el.querySelector("span").innerText;
            if (index == 3) {
                textArr[index] = el.querySelector("input").checked.toString();
            }
        });
        TempTable[TempTable.length - 1].Data.push(textArr);
    }
}
