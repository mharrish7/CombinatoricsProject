let mode = 0;
        let no = 0;
        let ax,ay,bx,by;
        let selected = 0;
        let selectedele = "";
        let targetNode, rect;
        let adjmatrix = [];
        document.addEventListener('click', function(e){
            if(mode == 0){
            no += 1;
            console.log('sdsd');
            let box = document.createElement('div');
            box.className = 'dropbox2';
            box.classList.add("d" + no);
            box.style.position = "absolute";
            box.style.left = e.clientX + "px";
            box.style.top = e.clientY + "px";
            box.innerText = "d" + no;
            let i = box;
            
            document.body.appendChild(box);

            
            i.addEventListener("click" , e => {
                if(mode == 1){
                    console.log('ssd');
                    if(selected == 1){
                        console.log("selected 2");
                        selected = 0;
                        rect = i.getBoundingClientRect();
                        targetNode = i;
                        bx = targetNode.offsetLeft + targetNode.offsetWidth / 2;
                        by = targetNode.offsetTop + targetNode.offsetHeight / 2;
                        console.log([ax,ay,bx,by]); 
                        document.querySelector('.' + selectedele).style.backgroundColor = "grey";
                        if(selectedele != i.classList[1]){
                        adjmatrix.push([selectedele,i.classList[1]]);
                        linedraw(parseInt(ax),parseInt(ay),parseInt(bx),parseInt(by));
                        }
                        selectedele = "";

                    }
                    else{
                        selected += 1;
                        var rect = i.getBoundingClientRect();
                        let targetNode = i;
                        ax = targetNode.offsetLeft + targetNode.offsetWidth / 2;
                        ay = targetNode.offsetTop + targetNode.offsetHeight / 2; 
                        console.log([ax,ay]);
                        selectedele = i.classList[1];
                        console.log(selected);
                        i.style.backgroundColor = "orange";
                    };
                };
            });
            }
        });
        

        const cal = () => {
            for(i of document.querySelectorAll(".dropbox2")){
                if(i.innerHTML.trim() == ""){
                    continue;
                }
                else{
                    console.log(i.classList[1]);
                    var rect = i.getBoundingClientRect();
                    let targetNode = i;
                    let centerX = targetNode.offsetLeft + targetNode.offsetWidth / 2;
                    let centerY = targetNode.offsetTop + targetNode.offsetHeight / 2;    
                    console.log(centerX);
                    console.log(centerY);           
                    }
            }
        }
        
        function linedraw(ax, ay, bx, by) {
            if(ax > bx) {
                bx = ax + bx; 
                ax = bx - ax;
                bx = bx - ax;
        
                by = ay + by;
                ay = by - ay;
                by = by - ay;
            }
        
            let distance = Math.sqrt(Math.pow(bx - ax, 2) + Math.pow(by - ay, 2));
            let calc = Math.atan((by - ay) / (bx - ax));
            let degree = calc * 180 / Math.PI;
            
            let line = document.createElement('div');
            line.className = "line";
            line.style.position = 'absolute';
            line.style.height = "1px";
            line.style.transformOrigin = "top left";
            line.style.width = String(distance) + 'px';
            line.style.top = ay + "px";
            line.style.left = ax + "px";
            line.style.transform = `rotate(${degree}deg)`;
            line.style.backgroundColor = "black";
            document.body.appendChild(line);
        }


function sendall(){
    let adj1 = []
    for(i of adjmatrix){
        adj1.push(i[0]);
        adj1.push(i[1]);
    }
    $.ajax({
        url: '/data',
        data: {
            info : adj1,
        },
        type: 'POST'
    }).done(function (data) {
        let colorb = ['red','green','blue','orange','pink'];
        let box = document.querySelectorAll('.dropbox2');
        for(const i in box){
            let dat = data.data;
            let ind = dat[parseInt(box[i].classList[1][1])-1];
            const col = colorb[ind-1];
            console.log([box[i].classList[1],ind,col]);
            box[i].style.backgroundColor = col;
        }
    })
}

const addv = document.querySelector('.addv');
const adde = document.querySelector('.adde')
addv.disabled = true;
document.querySelector('.colorb').disabled = true;

addv.addEventListener('click' , function(){
    addv.disabled = true;
    adde.disabled = false;
    document.querySelector('.colorb').disabled = true;
    setTimeout(() => {mode = 0}, 200);

})

adde.addEventListener('click' , function(){
    mode = 1;
    adde.disabled = true;
    addv.disabled = false;
    document.querySelector('.colorb').disabled = false;


})

document.querySelector('.colorb').addEventListener('click', sendall ); 

document.querySelector('.reset').addEventListener('click' , function(){
    mode = 1;
    for(i of document.querySelectorAll('.dropbox2')){
        i.remove();
    }

    for(i of document.querySelectorAll('.line')){
        i.remove();
    }

    setTimeout(() => {mode = 0;},200);
    no = 0;
})