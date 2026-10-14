// llm_test.mjs —— 放在 02_大模型基础 文件夹里，用已安装的 Node.js 运行
// 用法：  cd /d C:\Users\Doris\Desktop\LightChaser-Training-53\02_大模型基础
//         node llm_test.mjs
//
// 说明：Node 18+ 自带 fetch，不需要装任何库（第 3 步的 pip install 在这里用不上）

import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

// 1) 读取「本文件所在目录」的 .env（不依赖当前工作目录，放哪都能找到）
const here = path.dirname(fileURLToPath(import.meta.url));
const envPath = path.join(here, '.env');
const envText = fs.readFileSync(envPath, 'utf8');

// 2) 极简解析 .env：一行一个 KEY=value，# 开头是注释
const env = {};
for (const line of envText.split(/\r?\n/)) {
  const s = line.trim();
  if (!s || s.startsWith('#')) continue;
  const i = s.indexOf('=');
  if (i > 0) env[s.slice(0, i).trim()] = s.slice(i + 1).trim();
}

const key = env.DEEPSEEK_API_KEY;
if (!key) {
  console.error('× 没读到 DEEPSEEK_API_KEY，请检查 .env 的内容是否为：DEEPSEEK_API_KEY=sk-xxxx');
  process.exit(1);
}

// 3) 调用 DeepSeek（OpenAI 兼容接口，只换 base_url）
const resp = await fetch('https://api.deepseek.com/chat/completions', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json',
    'Authorization': `Bearer ${key}`,
  },
  body: JSON.stringify({
    model: 'deepseek-chat',                       // 推理版用 deepseek-reasoner
    messages: [
      { role: 'system', content: '你是一名耐心的大一助教' },
      { role: 'user', content: '用三句话解释什么是边缘检测' },
    ],
  }),
});

// 4) 出错时把服务端返回的原文打出来，方便排查（不会打印 Key）
if (!resp.ok) {
  console.error('× 请求失败：HTTP ' + resp.status);
  console.error(await resp.text());
  process.exit(1);
}

const data = await resp.json();
console.log('----- DeepSeek 的回答 -----');
console.log(data.choices[0].message.content);
