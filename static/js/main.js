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
            box.style.left = e.clientX - 50 + "px";
            box.style.top = e.clientY - 50 + "px";
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
                        if(selectedele != i.classList[1]){
                        document.querySelector('.' + selectedele).style.backgroundColor = "rgb(221,224,255)";
                        document.querySelector('.' + selectedele).style.backgroundImage = "linear-gradient(245deg, rgba(221,224,255,1) 0%, rgba(249,122,255,1) 100%)";
                        i.style.backgroundColor = "rgb(221,224,255)";
                        i.style.backgroundImage = "linear-gradient(245deg, rgba(221,224,255,1) 0%, rgba(249,122,255,1) 100%)";
                        }
                        else{
                        i.style.backgroundColor = "#FFDEE9";
                        i.style.backgroundImage = "linear-gradient(0deg, #FFDEE9 0%, #B5FFFC 100%)";
                        }
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
                        i.style.backgroundColor = "#FAD961";
                        i.style.backgroundImage = "linear-gradient(90deg, #FAD961 0%, #F76B1C 100%)";
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
            line.style.transformOrigin = "top left";
            line.style.width = String(distance) + 'px';
            line.style.top = ay + "px";
            line.style.left = ax + "px";
            line.style.transform = `rotate(${degree}deg)`;
            line.style.zIndex = "-1";
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
        let colorb = ['rgb(180,190,255)','rgb(255,180,180)','rgb(244,250,138)','rgb(138,241,190)'];
        let colorb2 = ['linear-gradient(245deg, rgba(180,190,255,1) 0%, rgba(82,112,240,1) 71%)','linear-gradient(245deg, rgba(255,180,180,1) 0%, rgba(240,82,82,1) 70%)','linear-gradient(245deg, rgba(138,241,190,1) 0%, rgba(38,148,67,1) 70%)','linear-gradient(245deg, rgba(244,250,138,1) 0%, rgba(221,233,170,1) 70%)'];
        let box = document.querySelectorAll('.dropbox2');
        let ma = -1;
        for(const i in box){
            console.log(i);
            if(i == "entries"){
                break;
            }
            let dat = data.data;
            let ind = dat[parseInt(box[i].classList[1].slice(1))-1];
            ma = (ind) > ma ? (ind) : ma;
            const col = colorb[ind-1];
            const col2 = colorb2[ind-1];
            console.log([box[i].classList[1],ind,col,col2]);
            box[i].style.backgroundColor = col;
            box[i].style.background = colorb2[ind-1];

        }
        //console.log("sdsdsd" + ma);
        document.querySelector('.result').innerText = ma;
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
    adjmatrix = [];
    setTimeout(() => {addv.disabled = true;
        adde.disabled = false;
        document.querySelector('.colorb').disabled = true;
        setTimeout(() => {mode = 0}, 200);},200);
    no = 0;
})