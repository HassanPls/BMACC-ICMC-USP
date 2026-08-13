async function buscarDados() {
  await new Promise((resolve) => {
    setTimeout(() => {
        let dados = ["Pedro", "Luiz"]
      console.log(dados);
      resolve(dados);
    }, 3000);
  });
}

async function timeout(ms) {
  return new Promise((_, reject) => {
    setTimeout(() => {
      reject(new Error("Tempo limite excedido"));
    }, ms);
  });
}

async function executar() {
  try {
    const resultado = await Promise.race([buscarDados(), timeout(5000)]);
    console.log("Sucesso: ", resultado);
  } catch (error) {
    console.error(error.message);
  }
}

executar()