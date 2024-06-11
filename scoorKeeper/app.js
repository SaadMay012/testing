p1S = document.querySelector("#p1Scoor");
p2S = document.querySelector("#p2Scoor");

p1Button = document.querySelector("#p1Butoon");
p2Button = document.querySelector("#p2Butoon");
resetButon = document.querySelector("#reset");

selct = document.querySelector('#game')

let winingScoor = 5;
let p1 = 0;
let p2 = 0;

let GameOver = false;


p1Button.addEventListener('click',function(){
  if(!GameOver){
    p1 += 1;
    if(winingScoor<=p1){
        GameOver = true;
    }
    p1S.textContent = p1;
}    
})


p2Button.addEventListener('click',function(){
    if(!GameOver){
      p2 += 1;
      if(winingScoor<=p2){
        GameOver = true;
      }
      p2S.textContent = p2;

}
})

resetButon.addEventListener('click',function(){
    GameOver = false;
    p1 = 0;
    p2S.textContent = 0;
})