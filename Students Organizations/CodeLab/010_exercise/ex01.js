const valores = [1, 2, 3, 4, 5];

function maiorQueDois(valor) {
  if (valor > 2) {
    return true;
  } else {
    return false;
  }
}

function filtrar(valores, filtro) {
  let newArray = [];
  for (const item of valores) {
    if (filtro(item)) {
        newArray.push(item);
    }
  }

  return newArray;
}

console.log(filtrar(valores, maiorQueDois));
